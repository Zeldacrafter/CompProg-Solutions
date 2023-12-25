#include "../utils.cc"

// SRC: https://github.com/Zeldacrafter/CompProg/blob/master/code/graphs/pushRelabel.cc
template <typename F>
struct edge {
  edge(int from, int to, F capacity, F flow = 0)
      : mfrom(from), mto(to), mcapacity(capacity), mflow(flow) {}
  int mfrom, mto;
  F mcapacity, mflow;
  int other(int v) { return v == mfrom ? mto : mfrom; }
  F capacity(int v) { return v == mfrom ? mcapacity : 0; }
  F flow(int v) { return v == mfrom ? mflow : -mflow; }
  void adjust(int v, F amount) {
    mflow += v == mfrom ? amount : -amount;
  }
};

template <typename F = ll>
struct PR {
  vi label, currentEdge;
  vector<F> excess;
  queue<int> active;
  vvi adj;
  vector<edge<F>> edges;
  int S, T;
  PR(int n, int s = -1, int t = -1) { reset(n, s, t); }
  int add(int from, int to, F c = numeric_limits<F>::max(), F f = 0) {
    edges.eb(from, to, c, f);
    adj[from].pb(SZ(edges) - 1);
    adj[to].pb(SZ(edges) - 1);
    return SZ(edges) - 1;
  }
  void clear() { edges.clear(); adj.clear(); }
  void reset(int n, int s = -1, int t = -1) {
    clear();
    adj.resize(n + (s == -1) + (t == -1));
    S = s == -1 ? n : s;
    T = t == -1 ? n + (s == -1) : t;
  }
  void push(int v, edge<F>& e) {
    F more = min(excess[v], e.capacity(v) - e.flow(v));
    excess[e.other(v)] += more;
    excess[v] -= more;
    e.adjust(v, more);
    if (more && excess[e.other(v)] == more) active.push(e.other(v));
  }
  void relabel(int v) {
    int m = numeric_limits<int>::max();
    for (int i : adj[v]) {
      auto& e = edges[i];
      if (e.flow(v) < e.capacity(v)) ckmin(m, label[edges[i].other(v)]);
    }
    if (m < numeric_limits<int>::max()) label[v] = m + 1;
  }
  void discharge(int v) {
    while (excess[v]) {
      auto& e = edges[adj[v][currentEdge[v]]];
      if (label[v] - 1 == label[e.other(v)] &&
          e.flow(v) < e.capacity(v))
        push(v, e);
      else if (SZ(adj[v]) == ++currentEdge[v]) {
        currentEdge[v] = 0;
        relabel(v);
      }
    }
  }
  F maxflow(int s, int t) {
    currentEdge.assign(SZ(adj), 0);
    label.assign(SZ(adj), 0);
    excess.assign(SZ(adj), 0);
    excess[s] = numeric_limits<F>::max();
    label[s] = SZ(adj);
    for (int i : adj[s]) push(s, edges[i]);
    while (!active.empty()) {
      if (active.front() != s && active.front() != t)
        discharge(active.front());
      active.pop();
    }
    F maxflow = 0;
    for (int i : adj[s]) maxflow += edges[i].flow(s);
    return maxflow;
  }
};

int dfs(PR<ll>& pr, int curr = 0) {
    static set<int> seen;
    if(seen.count(curr)) return 0;
    seen.insert(curr);

    int res = 1;
    for(int i : pr.adj[curr])
        if(pr.edges[i].capacity(curr) > pr.edges[i].flow(curr))
            res += dfs(pr, pr.edges[i].other(curr));
    return res;
}

void solve() {
    map<string, int> toInd;
    auto getInd = [&](string s) {
        if(toInd.count(s)) return toInd[s];
        return toInd[s] = SZ(toInd);
    };
    set<ii> inp;

    getInp([&](auto& cin, int) {
        string s1, s2;
        cin >> s1;
        s1.pop_back();

        int i = getInd(s1);
        while(cin >> s2) {
            int j = getInd(s2);
            if(!inp.count({j, i})) inp.emplace(i, j);
        }
    });
    int N = SZ(toInd);

    PR pr(N, 0, N - 1);
    for(auto [i, j] : inp) {
        pr.add(i, j, 1);
        pr.add(j, i, 1);
    }
    assert(pr.maxflow(0, N - 1) == 3);
    int cutSize = dfs(pr, 0);
    cout << cutSize*(N-cutSize) << endl;
}


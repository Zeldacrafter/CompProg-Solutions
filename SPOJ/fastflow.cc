#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR (a, 0, (b))
#define CEIL(a, b) ((a) + (b)-1) / (b)
template <class T>
bool ckmin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
  if (DEBUG) std::cerr
#define dvar(...) " [" << #__VA_ARGS__ ": " << mt(__VA_ARGS__) << "] "
template <typename T>
struct IsC {
  template <typename C>
  static char test(typename C::const_iterator*);
  template <typename C>
  static int test(...);
  static const bool value = sizeof(test<T>(0)) == sizeof(char);
};
template <>
struct IsC<string> {
  static const bool value = false;
};
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream&, const C&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);
template <typename... T> using TS = tuple_size<tuple<T...>>;
template<size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return o << ", " << get<idx>(t) << ')';
}
template<size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << ", " << get<idx>(t), t);
}
template<size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << '(' << get<idx>(t), t);
}
template<typename T>
ostream& operator<<(ostream& o, const tuple<T>& t) {
  return o << get<0>(t);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
  return o << mt(p.fi, p.se);
}
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(
    ostream& o, const C& c) {
  o << '[';
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    o << *it << (next(it) != c.cend() ? ", " : "");
  return o << ']';
}
template <typename T>
void tprint(vector<vector<T>>& v, size_t width = 0, ostream& o = cerr) {
  if (!DEBUG) return;
  for (auto& vv : v) {
    for (auto& i : vv) o << setw(width) << i;
    o << endl;
  }
}


struct edge {
  edge(int from, int to, ll capacity, ll flow = 0)
      : mfrom(from), mto(to), mcapacity(capacity), mflow(flow) {}
  int mfrom, mto;
  ll mcapacity, mflow;
  int other(int v) { return v == mfrom ? mto : mfrom; }
  ll capacity(int v) { return v == mfrom ? mcapacity : 0; }
  ll flow(int v) { return v == mfrom ? mflow : -mflow; }
  void adjust(int v, ll amount) {
    mflow += v == mfrom ? amount : -amount;
  }
};
vector<edge> edges;
vvi adj;
void addEdge(int from, int to, ll c, ll f = 0) {
  edges.eb(from, to, c, f);
  adj[from].pb(SZ(edges) - 1);
  adj[to].pb(SZ(edges) - 1);
}
ostream& operator<<(ostream& o, const edge& e) {
  return o << e.mfrom << "-- " << e.mflow << '/' << e.mcapacity << " -->" << e.mto;
}


vi dist, ptr;
const ll inf = 1e16;
bool dinic_bfs(int s, int t) {
  dist.assign(SZ(adj), SZ(adj));
  queue<int> q;
  q.push(s);
  dist[s] = 0;
  while (SZ(q)) {
    int v = q.front(); q.pop();
    for (int i : adj[v]) {
      edge& e = edges[i];
      if (dist[e.other(v)] == SZ(adj) && e.flow(v) < e.capacity(v)) {
        dist[e.other(v)] = dist[v] + 1;
        q.push(e.other(v));
      }
    }
  }
  return dist[t] < SZ(adj);
}
ll dinic_dfs(int v, int t, ll available) {
  if (v == t || !available) return available;
  ll pushed = 0;
  for (; ptr[v] < SZ(adj[v]); ++ptr[v]) {
    edge& e = edges[adj[v][ptr[v]]];
    if (dist[v] + 1 != dist[e.other(v)])
      continue;
    ll wasPushed =
        dinic_dfs(e.other(v), t,
                  min(available - pushed, e.capacity(v) - e.flow(v)));
    pushed += wasPushed;
    e.adjust(v, wasPushed);
    if (pushed == available) return pushed;
  }
  return pushed;
}
ll maxflow(int s, int t) {
  dist.assign(SZ(adj), 0);
  ll f = 0;
  while (1) {
    if (!dinic_bfs(s, t)) return f;
    ptr.assign(SZ(adj), 0);
    f += dinic_dfs(s, t, inf);
  }
}

void solve() {
    int n, m;
    cin >> n >> m;

    edges.clear();
    adj.assign(n, vi());

    F0R(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if(a == b) continue;

        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    cout << maxflow(0, n - 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);

  int tt = 1;
  FOR (t, 1, tt + 1) {
    solve();
  }
  
  return 0;
}


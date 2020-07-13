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

struct LCA {
  vi height, eulerTour, first;
  vvi idx;
  LCA(vvi& adj, int root = 0)
      : height(SZ(adj), -1), first(SZ(adj), -1) {
    dfs(adj, root);
    build();
  }
  void build() {
    const int logn = ceil(log2l(SZ(eulerTour))) + 1;
    idx.assign(SZ(eulerTour), vi(logn));
    F0R (i, SZ(eulerTour))
      idx[i][0] = eulerTour[i];
    for (int j = 1; (1 << j) <= SZ(eulerTour); ++j)
      for (int i = 0; i + (1 << j) <= SZ(eulerTour); ++i) {
        int k = i + (1 << (j - 1));
        idx[i][j] = height[idx[i][j - 1]] < height[idx[k][j - 1]]
			? idx[i][j - 1] : idx[k][j - 1];
      }
  }
  int rmq(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return height[idx[l][k]] < height[idx[r - (1 << k) + 1][k]]
               ? idx[l][k] : idx[r - (1 << k) + 1][k];
  }
  void dfs(vvi& adj, int v = 0, int h = 0) {
    eulerTour.pb(v);
    first[v] = SZ(eulerTour) - 1;
    height[v] = h;
    for (int u : adj[v])
      if (first[u] == -1) {
        dfs(adj, u, h + 1);
        eulerTour.pb(v);
      }
  }
  int lca(int a, int b) {
    return rmq(min(first[a], first[b]), max(first[a], first[b]));
  }
};


void solve() {
    int n, m;
    cin >> n >> m;

    vi index(m),
       iteration(m + n + 1),
       inTower(n);
    iota(ALL(index), 0);
    F0R(i, n) {
        cin >> inTower[i];
        inTower[i]--;
    }

    vvi adj(2*m);
    F0R(i, m - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        int nodeNr = m + i;
    
        adj[index[a]].pb(nodeNr);
        adj[nodeNr].pb(index[a]);

        adj[index[b]].pb(nodeNr);
        adj[nodeNr].pb(index[b]);

        index[a] = index[b] = nodeNr;
        iteration[nodeNr] = i + 1;

    }

    LCA lca(adj, 2*m - 2);

    vi res(m);
    F0R(i, n - 1) {
        if(inTower[i] == inTower[i + 1])
            res[0]++;
        else {
            int v = lca.lca(inTower[i], inTower[i + 1]);
            res[iteration[v]]++;
        }
    }

    int sum = 0;
    F0R(i, m) {
        sum += res[i];
        cout << n - sum - 1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc = 1;
    FOR(i, 1, tc + 1) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}


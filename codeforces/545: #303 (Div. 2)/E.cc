#include <bits/stdc++.h>
using namespace std;

#define int long long
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
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define SET(a, b) memset((a), (b), sizeof(a))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
  if (DEBUG) std::cerr
#define dvar(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
template <class a, class b>
ostream& operator<<(ostream& o, const pair<a, b>& p);
template <class T> struct IsC {
  template <class C> static char test(typename C::const_iterator*);
  template <class C> static int test(...);
  static const bool value = sizeof(test<T>(0)) == sizeof(char);
};
template <> struct IsC<string> { static const bool value = false; };
template <class C> typename enable_if<IsC<C>::value, ostream&>::type operator<<( ostream& o, const C& c) {
  o << '{';
  for (auto it = c.begin(); it != c.end();)
    o << *it << (++it != c.end() ? ", " : "}");
  return o;
}
template <class a, class b> ostream& operator<<(ostream& o, const pair<a, b>& p) {
  return o << '(' << p.fi << ", " << p.se << ')';
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

	vector<vector<tuple<int, int, int>>> adj(n);
    vi e(m);
    F0R(i, m) {
        int u, v, k;
        cin >> u >> v >> k;
		u--; v--;

		adj[v].eb(k, u, i);
		adj[u].eb(k, v, i);
        e[i] = k;
    }

    int u;
    cin >> u; u--;

	vii d(n, mp(-1, -1));
    set<ii> q;
    q.emplace(0, u);

    d[u] = mp(0, -1);
    
    while(!q.empty()) {
        auto [dist, curr] = *q.begin();
        q.erase(q.begin());

        if(d[curr].fi != -1 && dist > d[curr].fi) continue;
        
        for(auto [dist2, v, i] : adj[curr]) {
            
            if(d[v].fi == -1 || d[v].fi > dist + dist2 || (d[v].fi == dist + dist2 && e[d[v].se] > dist2)) {
                d[v] = mp(dist + dist2, i);
                q.emplace(dist + dist2, v);
            }
        }
    }
    
    int sum = 0;
    for(auto[dist, i] : d)
        if(dist) sum += e[i];
    cout << sum << endl;
    for(auto[dist, i] : d)
        if(dist) cout << i + 1 << ' ';

}


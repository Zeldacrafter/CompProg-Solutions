#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SZ(x) (int)(x).size()
//#define endl '\n'
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


void solve() {
    int a, b, m, l, k;
    cin >> a >> b >> m >> l >> k;

    vvii adj(a + b);
    F0R(i, m) {
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        adj[u].eb(v, x);
        adj[v].eb(u, x);
    }

    vvvi dist(a+b, vvi(l + 1, vi(k + 1, (int)4e9)));
    set<array<int, 4>> q;
    q.insert({0, a + b - 1, 0, k});
    dist[a + b - 1][0][k] = 0;

    while(!q.empty()) {

        int d = (*q.begin())[0],
            u = (*q.begin())[1],
            dLeft = u >= a ? 0 : (*q.begin())[2],
            charges = (*q.begin())[3];

        q.erase(q.begin());

        if(dist[u][dLeft][charges] < d) continue;

        if(!u) {
            cout << d << endl;
            return;
        }

        for(auto x : adj[u]) {
            int v = x.fi, dv = x.se;
            if(dLeft >= dv && ckmin(dist[v][dLeft - dv][charges], d))
                q.insert({d, v, dLeft - dv, charges});
            else {
                if (charges && dv <= l && ckmin(dist[v][l - dv][charges - 1], d))
                    q.insert({d, v, l - dv, charges - 1});
                
                if(ckmin(dist[v][0][charges], d + dv))
                    q.insert({d + dv, v, 0, charges});
            }
        }
    }

    assert(false);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

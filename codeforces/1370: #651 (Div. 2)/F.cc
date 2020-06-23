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
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SZ(x) (int)(x).size()
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

vvi adj;
vi rootDist;

void rootTree(int curr, int p = -1) {
    rootDist[curr] = p == -1 ? 0 : rootDist[p] + 1;

    for(int u : adj[curr])
        if(u != p)
            rootTree(u, curr);
}

ii query(int depth, int other = -1) {
    vi a;
    F0R(i, SZ(rootDist)) 
        if(rootDist[i] == depth && other != i) 
            a.pb(i);

    if(!SZ(a)) return mp(-1, -1);

    cout << "? " << SZ(a);
    for(int i : a) cout << ' ' << i + 1;
    cout << endl;

    int node, dist;
    cin >> node >> dist;
    node--;
    return mp(node, dist);
}

void solve() {
    int n;
    cin >> n;

    adj = vvi(n);
    F0R(i, n - 1) { 
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[v].pb(u);
        adj[u].pb(v);
    }

    cout << "? " << n;
    F0R(i, n) cout << ' ' << i + 1;
    cout << endl;

    int root, dist;
    cin >> root >> dist;
    root--;

    rootDist = vi(n);
    rootTree(root);

    int l = (dist+1)/2;
    int r = min(dist, *max_element(ALL(rootDist)));
	int fstNode = -1;
    while(l <= r) {
        int mid = (l+r)/2;

        auto [node, newDist] = query(mid);
        if(newDist != dist || node == -1)
            r = mid - 1;
        if(newDist == dist) {
            l = mid + 1;
            fstNode = node;
        }
    }

    // Get nodes with dist to fstNode
    queue<ii> q;
    q.emplace(fstNode, 0);
    vi seen(n);
    seen[fstNode] = true;
    vi possSnd;
    while(!q.empty()) {
        auto [curr, dist2] = q.front();
        q.pop();

        if(dist2 == dist) 
            possSnd.pb(curr);

        for(int i : adj[curr]) if(!seen[i]) {
			q.emplace(i, dist2 + 1);
			seen[i] = true;
		}
    }

    cout << "? " << SZ(possSnd);
    for(int i : possSnd) cout << ' ' << i + 1;
    cout << endl;

    int sndNode, secDist;
    cin >> sndNode >> secDist;

    cout << "! " << fstNode + 1 << ' ' << sndNode << endl;

    string s;
    cin >> s;
    assert(s[0] == 'C');
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) solve();
}



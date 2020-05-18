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


int n;

void solve() {
    map<int, string> toStr;
    map<string, int> toInt;
    F0R(i, n) {
        string s;
        cin >> s;
        toInt[s] = i;
        toStr[i] = s;
    }

    int m;
    cin >> m;

    vvi adj(n);
    vi in(n);
    F0R(i, m) {
        string s1, s2;
        cin >> s1 >> s2;
        adj[toInt[s1]].pb(toInt[s2]);
        in[toInt[s2]]++;
    }

    set<int> q;
    F0R(i, n)
        if(!in[i])
            q.insert(i);

    while(!q.empty()) {
        int curr = *q.begin();
        q.erase(q.begin());

        cout << ' ' << toStr[curr];

        for(int v : adj[curr])
            if(--in[v] == 0)
                q.insert(v);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int tc = 1;;++tc) {
        if(!(cin >> n))
            break;
        cout << "Case #" << tc << ": Dilbert should drink beverages in this order:";
        solve();
        cout << ".\n\n";
    }
}

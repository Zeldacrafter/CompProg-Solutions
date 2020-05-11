#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int rs, cs;
    while(cin >> rs >> cs) {
        vvi a(rs, vi(cs));
        F0R(r, rs) 
            F0R(c, cs) 
                cin >> a[r][c];

        vvi dp(rs, vi(cs));
        F0R(r, rs)
            dp[r][cs - 1] = a[r][cs - 1];

        R0F(c, cs - 2)
            F0R(r, rs)
                dp[r][c] = a[r][c] + min({dp[(r - 1 + rs) % rs][c + 1], dp[r][c + 1], dp[(r + 1) % rs][c + 1]});

        int maxRow = 0;
        F0R(r, rs)
            if(dp[r][0] < dp[maxRow][0])
                maxRow = r;

        cout << maxRow + 1;
        for(int r = maxRow, c = 0; c < cs - 1; ++c) {
            ll prev = dp[r][c] - a[r][c];
            if(r == rs - 1) {
                if(prev == dp[0][c + 1])
                    r = 0;
                else if(prev == dp[(r - 1 + rs) % rs][c + 1])
                    r--;
            } else if(!r) {
                if(prev == dp[r][c + 1]);
                else if(prev == dp[(r + 1) % rs][c + 1])
                    r++;
                else
                    r = rs - 1;
            } else {
                if(prev == dp[r - 1][c + 1])
                    r--;
                else if(prev == dp[r][c + 1]);
                else
                    r++;
            }
            cout << ' ' << r + 1;
        }
        
        cout << endl << dp[maxRow][0] << endl;
    }
}

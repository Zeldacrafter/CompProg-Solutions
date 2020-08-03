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
#define pf push_front
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define SZ(x) (int)(x).size()
#define ft front()
#define bk back()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define SET(a, b) memset((a), (b), sizeof(a))
template <class t>
bool ckmin(t& a, const t& b) {
  return a > b ? a = b, true : false;
}
template <class t>
bool ckmax(t& a, const t& b) {
  return a < b ? a = b, true : false;
}
#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
  if (DEBUG) std::cerr
#define dvar(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
template <class a, class b>
ostream& operator<<(ostream& o, const pair<a, b>& p);
template <class T>
struct IsC {
  template <class C>
  static char test(typename C::const_iterator*);
  template <class C>
  static int test(...);
  static const bool value = sizeof(test<T>(0)) == sizeof(char);
};
template <>
struct IsC<string> {
  static const bool value = false;
};
template <class C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(
    ostream& o, const C& c) {
  o << '{';
  for (auto it = c.begin(); it != c.end();)
    o << *it << (++it != c.end() ? ", " : "}");
  return o;
}
template <class a, class b>
ostream& operator<<(ostream& o, const pair<a, b>& p) {
  return o << '(' << p.fi << ", " << p.se << ')';
}

int d(int a, int b, int c) {
    return max({a, b, c}) - min({a, b, c}) + 1;
}

void solve() {
    string s;
    cin >> s;

    int last1, last2, last3, best1, best2, best3;
    last1 = last2 = last3 = best1 = best2 = best3 = -1;

    for(int i = 0; i < SZ(s); ++i) {
        int num = s[i] - '0';
        if(num == 1)
            last1 = i;
        else if(num == 2)
            last2 = i;
        else if(num == 3)
            last3 = i;

        if(last1 != -1 && last2 != -1 && last3 != -1 && (best1 == -1 || best2 == -1 || best3 == -1 || d(last1, last2, last3) < d(best1, best2, best3))) {
            best1 = last1;
            best2 = last2;
            best3 = last3;
        }
    }
    if(best1 == -1 || best2 == -1 || best3 == -1)
        cout << 0 << endl;
    else
        cout << d(best1, best2, best3) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


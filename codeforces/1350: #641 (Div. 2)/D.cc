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


void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n), todo;
    F0R(i, n) {
        cin >> a[i];
        if(a[i] == k)
            todo.pb(i);
    }

    if(SZ(todo) == n) {
        cout << "yes\n";
        return;
    }
    
    R0F(m, SZ(todo) - 1) {
        int lower = 0, higher = 0, medCnt = 1;
        for(int i = n - 1; ~i && (!m || i > todo[m - 1]); --i) {

            if(a[i] < k)
                lower++;
            else if(a[i] > k)
                higher++;

            if(lower + 1 <= (lower + higher + 1)/2 && medCnt >= (lower + higher + 1)/2) {
                cout << "yes\n";
                return;
            }

            if(m && i - 1 == todo[m - 1] && lower - medCnt <= higher)
                m--;
        }
    }


    FOR(m, -1, SZ(todo)) {
        int lower = 0, higher = 0, medCnt = 1;
        for(int i = 0; i < n && (m == SZ(todo) - 1 || i < todo[m + 1]); ++i) {

            if(a[i] < k)
                lower++;
            else if(a[i] > k)
                higher++;
            
            if(lower + 1 <= (lower + higher + 1)/2 && medCnt >= (lower + higher + 1)/2) {
                cout << "yes\n";
                return;
            }

            if(m < SZ(todo) - 1 && i + 1 == todo[m + 1] && lower - medCnt <= higher)
                m++;
        }

    }

    cout << "no\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


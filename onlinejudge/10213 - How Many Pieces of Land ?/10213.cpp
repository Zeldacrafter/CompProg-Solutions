#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (x).size()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) for (auto(a) = 0; (a) < (b); ++(a))
#define R0F(a, b) for (auto(a) = (b); (a) >= 0; --(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))
#define ROFI(a, b) for (auto(a) = (b).rbegin(); (a) != (b).rend(); ++(a))
#define TRAV(a, b) for (auto &(a) : (b))
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t &a, const t &b) {
  return a > b ? a = b, true : false;
}
template <typename t> bool ckmax(t &a, const t &b) {
  return a < b ? a = b, true : false;
}

void prnt(unsigned __int128 n) {
    if(n < 0) {
        cout << '-';
        n *= -1;
    }
    long long mod = 1000000000000000000;
    string str;
    do {
        unsigned long long digits = n % mod;
        string digitStr = to_string(digits);
        string leading0s = (digits != n) ? string(18 - digitStr.length(), '0') : "";
        str = leading0s + digitStr + str;
        n = (n - digits) / mod;
    } while (n);
    cout << str; 
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    ll n;
    cin >> n;

    unsigned __int128 res = (unsigned __int128)n * (n - 1) * (n - 2) * (n - 3) / 24 + n * (n - 1) / 2 + 1;
    prnt(res);
    cout << endl;
  }

  return 0;
}

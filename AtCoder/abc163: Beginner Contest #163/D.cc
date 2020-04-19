#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

struct mod {
  static const ll p = 1e9 + 7;
  ll val;
  mod() : val(0) {}
  mod(ll val) : val(val % p) {}
  mod operator+(mod o) { return mod(val + o.val); }
  mod operator-(mod o) { return mod(val - o.val + p); }
  mod operator*(mod o) { return mod(val * o.val); }
  friend ostream& operator<<(ostream& o, mod m) {
    return o << m.val;
  }
};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;

    mod res = 0LL;
    FOR(i, k, n + 2)
        res = res + (i - 1)*i/2 - n*(n + 1)/2 + (n - i)*(n - i + 1)/2;
    cout << res << endl;
}



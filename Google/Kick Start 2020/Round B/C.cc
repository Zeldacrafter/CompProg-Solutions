#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
#define mp make_pair
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

struct mod {
  static const ll p = 1e9;
  ll val;
  mod() : val(0) {}
  mod(ll val) : val(val % p) {}
  mod operator+(mod o) { return mod(val + o.val); }
  mod operator-(mod o) { return mod(val - o.val + p); }
  mod operator*(mod o) { return mod(val * o.val); }
};

pair<mod, mod> evalProg(int& i, string& s) {

    mod r = 0, c = 0, amt = s[i] - '0';
    i += 2;
    while(s[i] != ')') {
        switch(s[i]) {
            case 'S':
                r = r + 1;
                break;
            case 'N':
                r = r - 1;
                break;
            case 'E':
                c = c + 1;
                break;
            case 'W':
                c = c - 1;
                break;
            default:
                pair<mod, mod> p = evalProg(i, s);
                c = c + p.se;
                r = r + p.fi;
                break;
        }
        i++;
    }
    return mp(r * amt, c * amt);
}

void solve() {
    string s;
    cin >> s;
    s = "1(" + s + ")";
    int i = 0;
    pair<mod, mod> res = evalProg(i, s);
    cout << res.se.val + 1 << ' ' << res.fi.val + 1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}


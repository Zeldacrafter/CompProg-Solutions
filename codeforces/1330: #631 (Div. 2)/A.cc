#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

bitset<1000> ok;
void solve() {
    ok.reset();
    ll n, x;
    cin >> n >> x;
    F0R(i, n) {
        ll k;
        cin >> k;
        ok[k] = true;
    }
    
    for(int i = 1;; ++i) {
        if(!ok[i]) {
            if(!x) {
                cout << i - 1 << endl;
                break;
            }
            x--;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


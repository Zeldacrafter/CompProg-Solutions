#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

void solve() {
    ll n;
    cin >> n;

    FOR(i, 2, 32) {
        if(n % ((1 << i) - 1) == 0) {
            cout << n/((1 << i) - 1) << endl;
            return;
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


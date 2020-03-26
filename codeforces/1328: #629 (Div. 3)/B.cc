#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

void solve() {
    ll n, k;
    cin >> n >> k;

    ll pos = n - 1, sum = 0, inc = 0;
    while(sum + ++inc < k) {
        sum += inc;
        pos--;
    }
    ll pos2 = n - (k - sum) + 1;

    FOR(i, 1, n + 1)
        cout << "ab"[i == pos || i == pos2];
    cout << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


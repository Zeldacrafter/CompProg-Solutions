#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve() {
    ll x, n, m;
    cin >> x >> n >> m;

    for(int i = 0; x/2 + 10 < x && i < n; ++i, x = x/2 + 10);
    cout << (x - 10*m <= 0 ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


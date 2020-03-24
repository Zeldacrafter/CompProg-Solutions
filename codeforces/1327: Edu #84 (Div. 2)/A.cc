#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;

    if((k & 1) != (n & 1)) {
        cout << "NO\n";
        return;
    }

    if(k*k > n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


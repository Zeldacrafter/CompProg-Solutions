#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, d;
    cin >> n >> d;

    ll x = 0;
    int lastVal = x + (ll)ceil(1.0*d/(1 + x));
    while(x <= n) {
        int res = x + (ll)ceil(1.0*d/(1 + x));

        if(res <= n) {
            cout << "YES\n";
            return;
        }
        if(res > lastVal) {
            cout << "NO\n";
            return;
        }
        lastVal = res;
        x++;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;

    while(tc--)
        solve();

    return 0;
}

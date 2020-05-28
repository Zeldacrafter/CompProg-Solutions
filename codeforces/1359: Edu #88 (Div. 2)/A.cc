#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define CEIL(a, b) ((a) + (b)-1) / (b)

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    cout << min(n/k, m) - CEIL(m - min(n/k, m), k - 1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


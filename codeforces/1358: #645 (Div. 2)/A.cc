#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve() {
    ll n, m;
    cin >> n >> m;
    cout << (n*m + 1)/2 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


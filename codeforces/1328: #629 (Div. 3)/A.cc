#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve() {
    ll a, b;
    cin >> a >> b;

    if(a % b)
        cout << b - a % b << endl;
    else
        cout << 0 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


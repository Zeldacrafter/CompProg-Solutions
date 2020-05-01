#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n;
    cin >> n;

    int a = (1 << n)       + ((1 << (n/2)) - 1) - 1;
    int b = ((1 << n) - 1) - ((1 << (n/2)) - 1);
    cout << abs(a - b) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


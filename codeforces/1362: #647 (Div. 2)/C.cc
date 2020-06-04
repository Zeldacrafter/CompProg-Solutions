#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
#define endl '\n'

void solve() {
    ull n;
    cin >> n;

    ull res = 0;
    for(int cnt = 0; n; ++cnt, n >>= 1)
        if(n & 1)
            res += (1ull << (cnt + 1)) - 1;
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


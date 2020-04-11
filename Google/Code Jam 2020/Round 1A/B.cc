#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

void solve() {
    int n;
    cin >> n;

    cout << 1 << ' ' << 1 << endl;
    n--;

    int r = 1, k = 1;
    while(n) {
        if(k == 1) {
            if(r > 1 && r <= n)
                r++, k++;
            else
                r++;
        } else {
            if(r <= n) 
                r++;
            else 
                k--;
        }

        if(k == 1)
            n--;
        else
            n -= r - 1;

        cout << r << ' ' << k << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ":\n";
        solve();
    }
}


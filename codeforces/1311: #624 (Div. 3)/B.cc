#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define endl '\n'

int ar[110] = {};
bitset<110> canSwap;

void solve() {
    memset(ar, 0, sizeof(ar));
    canSwap.reset();

    int n, m, p;
    cin >> n >> m;

    F0R(i, n)
        cin >> ar[i];
    F0R(i, m) {
        cin >> p;
        canSwap[p - 1] = true;
    }

    for(int i = 0, j = 1; i < n; i = j, j = i + 1) {
        while(j < n && canSwap[j - 1])
            j++;
        sort(ar + i, ar + j);
    }

    F0R(i, n - 1)
        if(ar[i] > ar[i + 1]) {
            cout << "NO" << endl;
            return;
        }

    cout << "YES" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--)
        solve();
}

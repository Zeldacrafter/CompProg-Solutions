#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, k;
    cin >> n >> k;

    int res = 0, nxt = k;
    for(int i = 0, j; i < n; ++i) {
        cin >> j;
        if(j != nxt)
            nxt = k;

        if(j == nxt) {
            if(nxt == 1) {
                res++;
                nxt = k;
            } else 
                nxt--;
        }
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}


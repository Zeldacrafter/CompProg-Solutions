#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define endl '\n'

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        int n, d, k;
        cin >> n >> d;

        int cnt;
        cin >> cnt;
        FOR(i, 1, n) {
            cin >> k;
            int amt = min(k, d / i);
            cnt += amt;
            d -= i * amt;
        }
        cout << cnt << endl;

    }
}

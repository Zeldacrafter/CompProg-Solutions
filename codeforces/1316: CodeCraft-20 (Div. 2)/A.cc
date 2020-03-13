#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n, m, k;
        cin >> n >> m;

        int sum = 0;
        F0R(i, n) {
            cin >> k;
            sum += k;
        }
        cout << min(m, sum) << endl;
    }
}

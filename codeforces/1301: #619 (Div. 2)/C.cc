#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;

        ll zeroes = n - m;
        ll groups = m + 1;
        ll k = zeroes / groups;
        cout << n * (n + 1) / 2 - k * (k + 1) / 2 * groups -
                    (k + 1) * (zeroes % groups)
             << endl;
    }

    return 0;
}

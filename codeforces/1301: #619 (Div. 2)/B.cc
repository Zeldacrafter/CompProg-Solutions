#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define endl '\n'

array<int, 100010> a;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;

        F0R(i, n)
            cin >> a[i];

        int minA = 1e9 + 1;
        int maxA = -1;
        int totalMax = -1;
        F0R(i, n) {
            if(a[i] == -1) {
                if(i > 0 && a[i - 1] != -1) {
                    minA = min(minA, a[i-1]);
                    maxA = max(maxA, a[i-1]);
                }
                if(i < n - 1 && a[i + 1] != -1) {
                    minA = min(minA, a[i+1]);
                    maxA = max(maxA, a[i+1]);
                }
            } else {
                if(i > 0 && a[i - 1] != -1)
                    totalMax = max(totalMax, abs(a[i] - a[i - 1]));
                if(i < n - 1 && a[i + 1] != -1)
                    totalMax = max(totalMax, abs(a[i] - a[i + 1]));
            }
        }

        if(maxA == -1)
            cout << max(0, totalMax) << ' ' << 0 << endl;
        else {
            int k = (minA + maxA) / 2;
            cout << max(totalMax, max(k - minA, maxA - k)) << ' ' << k << endl;
        }
    }

    return 0;
}

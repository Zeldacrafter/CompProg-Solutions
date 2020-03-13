#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define CEIL(a, b) ((a) + (b) - 1)/(b)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        ll n, g, b;
        cin >> n >> g >> b;

        ll daysA = CEIL(n, 2);
        ll daysB = max(0LL, b * (CEIL(daysA, g) - 1));
        cout << max(n, daysA + daysB) << endl;
    }

    return 0;
}

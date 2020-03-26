#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

bitset<1001> nums;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    if(n > m) {
        cout << 0 << endl;
        return 0;
    }

    vi a(n);
    F0R(i, n)
        cin >> a[i];

    ll res = 1;
    F0R(i, n)
        FOR(j, i + 1, n)
            res = (res * abs(a[i] - a[j])) % m;
    cout << res << endl;
}

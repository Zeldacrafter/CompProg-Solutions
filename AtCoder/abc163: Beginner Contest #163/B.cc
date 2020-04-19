#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m;
    ll sum = 0;
    F0R(i, m) {
        cin >> k;
        sum += k;
    }
    cout << (sum > n ? -1 : n - sum) << endl;
}



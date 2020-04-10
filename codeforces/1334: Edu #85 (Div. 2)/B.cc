#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    F0R(i, n)
        cin >> a[i];

    sort(RALL(a));

    int i = 0;
    ll sum = 0;
    while(i < n && sum + (a[i] - x) >= 0)
        sum += a[i++] - x;

    cout << i << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


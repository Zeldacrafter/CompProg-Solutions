#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <typename t> bool ckmin(t& a, const t& b) {return a > b ? a = b, true : false;}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    F0R (i, n)
        cin >> a[i];

    sort(ALL(a));

    vector<ll> prefSum(n + 1);
    F0R(i, n)
        prefSum[i + 1] = prefSum[i] + a[i];

    ll res = 1e18;
    for (int l = 0, r = 0; l < n; l = r) {
        while(r < n && a[r] == a[l])
            ++r;
        
        ll amt = r - l, 
           costL = l*(a[l] - 1) - prefSum[l],
           costR = prefSum[n] - prefSum[r] - (n - r) * (a[l] + 1);
        
        if (amt >= k)
            res = 0;

        if (amt + l >= k)
            ckmin(res, costL + k - amt);
        
        if (amt + n - r >= k)
            ckmin(res, costR + k - amt);

        ckmin(res, costL + costR + k - amt);
    }
    cout << max(res, 0ll);
}


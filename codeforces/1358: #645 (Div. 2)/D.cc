#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

ll gaus(ll x) {
    return x*(x + 1)/2;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    vector<ll> d(n*2), pSum(2*n), dSum(2*n);
    F0R(i, n) { 
        cin >> d[i];
        pSum[i] = (!i ? 0 : pSum[i - 1]) + gaus(d[i]);
        dSum[i] = (!i ? 0 : dSum[i - 1]) + d[i];
    }

    F0R(i, n) {
        d[n + i] = d[i];
        pSum[n + i] = pSum[n + i - 1] + gaus(d[i]);
        dSum[n + i] = dSum[n + i - 1] + d[i];
    }

    ll best = 0;
    F0R(i, n) {
        int ind = lower_bound(dSum.begin(), dSum.begin() + i + n, dSum[i + n] - x + 1) - dSum.begin();

        ll score = pSum[i + n] - (!ind ? 0 : pSum[ind - 1]);
        score -= gaus(dSum[i + n] - (!ind ? 0 : dSum[ind - 1]) - x);

        ckmax(best, score);
    }
    cout << best << endl;
}


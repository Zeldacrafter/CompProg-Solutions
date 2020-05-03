#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }

int n, d;
vector<ll> ang;
ll getScore(ll base) {
    ll left = d,
       best = 0,
       possLeft = 0;

    FOR(j, lower_bound(ALL(ang), base) - ang.begin(), n) {

        ll div = ang[j]/base;
        if(ang[j] % base || left < div) {
            possLeft += div;
        } else {
            left -= div;
            best += div - 1;
        }

    }

    if(left <= possLeft)
        return best + left;
    else 
        return d;
}

void solve() {
    cin >> n >> d;

    ang = vector<ll>(n);
    F0R(i, n)
        cin >> ang[i];

    sort(ALL(ang));

    ll res = d - 1;
    F0R(i, n) {
        ckmin(res, getScore(ang[i]));
        FOR(j, i + 1, n)
            if(ang[j] % ang[i] == 0)
                ckmin(res, getScore(ang[j]/ang[i]));
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

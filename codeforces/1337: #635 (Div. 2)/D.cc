#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <typename t> bool ckmin(t& a, const t& b) {return a > b ? a = b, true : false;}

ll calcDiff(ll a, ll b, ll c) {
    return (a - b)*(a - b) + (a - c)*(a - c) + (b - c)*(b - c);
}

ll getBest(vi& r, vi& g, vi& b) { 

    ll best = 4e18;
    F0R(i, SZ(r)) {
        ll curr1 = r[i];
        auto curr1It = lower_bound(ALL(g), r[i]);
        auto curr2It = upper_bound(ALL(b), r[i]);
        if(curr1It == g.end())
            continue;
        if(curr2It != b.begin())
            --curr2It;

        ckmin(best, calcDiff(curr1, *curr1It, *curr2It));
    }

    return best;
}

void solve() {
    int R, G, B;
    cin >> R >> G >> B;

    vi r(R), g(G), b(B);
    F0R(i, R) cin >> r[i];
    F0R(i, G) cin >> g[i];
    F0R(i, B) cin >> b[i];

    sort(ALL(r));
    sort(ALL(g));
    sort(ALL(b));

    ll res = getBest(r, g, b);
    ckmin(res, getBest(r, b, g));
    ckmin(res, getBest(g, r, b));   
    ckmin(res, getBest(g, b, r));   
    ckmin(res, getBest(b, r, g));   
    ckmin(res, getBest(b, g, r));   

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

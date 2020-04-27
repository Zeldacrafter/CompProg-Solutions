#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vi m(n, 0), ks(k, 0);
    F0R(i, n) {
        cin >> m[i];
        m[i]--;
    }
    F0R(i, k) cin >> ks[i];

    sort(ALL(m));

    vi resI;
    resI.pb(1);
    vvi res(1);
    res[0].pb(m[n - 1]);

    R0F(i, n - 2) {
        int l = 0, r = SZ(res);
        while(l < r) {
            int mid = (l + r) / 2;
            if(ks[m[i]] - resI[mid] > 0)
                r = mid;
            else
                l = mid + 1;
        }

        if(l >= SZ(res)) {
            resI.pb(1);

            vi tmp;
            tmp.pb(m[i]);

            res.pb(tmp);
        } else {
            assert(ks[m[i]] - resI[l] > 0);

            resI[l]++;
            res[l].pb(m[i]);
        }
    }

    cout << SZ(res) << endl;
    for(vi vek : res) {
        cout << SZ(vek);
        for(int i : vek)
            cout << ' ' << i + 1;
        cout << endl;
    }
}



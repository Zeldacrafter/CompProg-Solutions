#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (x).size()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) for (auto(a) = 0; (a) < (b); ++(a))
#define R0F(a, b) for (auto(a) = (b); (a) >= 0; --(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))
#define ROFI(a, b) for (auto(a) = (b).rbegin(); (a) != (b).rend(); ++(a))
#define TRAV(a, b) for (auto &(a) : (b))
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t &a, const t &b) {
  return a > b ? a = b, true : false;
}
template <typename t> bool ckmax(t &a, const t &b) {
  return a < b ? a = b, true : false;
}

bool same(const double& a, const double& b) {
    return abs(a - b) < 1e-9;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int tc = 1;; tc++) {
        int islandAmt, range;
        cin >> islandAmt >> range;

        if(!islandAmt && !range)
            break;

        bool possible = true;
        vector<pair<double, double>> needed(islandAmt, mp(-1.0, -1.0));
        F0R(i, islandAmt) {
            int x, y;
            cin >> x >> y;
            if(y > range) 
                possible = false;
            else {
                double diff = sqrt(range*range - y*y);
                needed[i] = mp(x - diff, x + diff);
            }
        }

        if(!possible) {
            cout << "Case " << tc << ": -1\n";
            continue;
        }

        sort(ALL(needed));

        int takenAmount = 0;
        int i = 0;
        while(i < SZ(needed)) {
            double low = needed[i].se;
            while(++i < SZ(needed) && needed[i].fi <= low)
                ckmin(low, needed[i].se);
            takenAmount++;
        }

        cout << "Case " << tc << ": " << takenAmount << endl;
    }




    return 0;
}

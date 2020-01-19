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
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (x).size()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) for (auto(a) = 0; (a) < (b); ++(a))
#define R0F(a, b) for (auto(a) = (b); (a) >= 0; --(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))
#define ROFI(a, b) for (auto(a) = (b).rbegin(); (a) != (b).rend(); ++(a))
#define TRAV(a, b) for (auto&(a) : (b))
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(1) {
        int roadLen;
        int gasStationAmt;

        cin >> roadLen >> gasStationAmt;

        if(!roadLen && !gasStationAmt)
            break;

        vii stations(gasStationAmt, ii(-1, -1));
        F0R(i, gasStationAmt) {
            int x, r;
            cin >> x >> r;
            stations[i] = ii(max(0, x - r), min(roadLen, x + r));
        }

        sort(stations.begin(), stations.end());

        int takenAmt = 0;
        int currPos = 0;
        int currIndex = 0;
        while(currPos < roadLen) {
            int newPos = currPos;
            while(currIndex < stations.size() && stations[currIndex].fi <= currPos) {
                ckmax(newPos, stations[currIndex].se);
                currIndex++;
            }
            if(newPos == currPos)
                break;

            currPos = newPos;
            takenAmt++;
        }
        
        if(currPos < roadLen)
            cout << -1 << endl;
        else
            cout << gasStationAmt - takenAmt << endl;
    }
    
    return 0;
}

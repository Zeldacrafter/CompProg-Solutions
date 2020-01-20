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
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pf push_front
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define SZ(x) (x).size()
#define ft front
#define bk back
#define ins insert
#define MID(a, b) (a + b) / 2
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

int gaus(int n) {
    return n*(n+1)/2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(!cin.eof()) {
        int thiefX;
        int thiefY = 0;

        int thiefDx, thiefDy;
        cin >> thiefX;
        if(cin.eof()) break;
        cin >> thiefDx >> thiefDy;

        if(!thiefX) {
            cout << 0 << endl;
            continue;
        }

        for(int i = 1;; ++i) {
            int dist = gaus(i);
            thiefX += thiefDx;
            thiefY += thiefDy;
            if(dist >= thiefX && dist >= thiefY) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}

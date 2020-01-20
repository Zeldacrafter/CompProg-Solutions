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
#define MID(a, b) (a + b + 1) / 2
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) for (auto(a) = 0; (a) < (b); ++(a))
#define R0F(a, b) for (auto(a) = (b); (a) >= 0; --(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))
#define ROFI(a, b) for (auto(a) = (b).rbegin(); (a) != (b).rend(); ++(a))
#define TRAV(a, b) for (auto &(a) : (b))
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t &a, const t &b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t &a, const t &b) { return a < b ? a = b, true : false; }

const ll range[] = {100, 10000 - 100, 1000000 - 10000, INT32_MAX};
const ll price[] = {2, 3, 5, 7};

ll getCost(ll a) {
    ll res = 0;
    int i = 0;
    while(a > 0) {
        ll amount = min(a, range[i]);
        res += price[i] * amount;
        a -= amount;
        ++i;
    }
    return res;
}

ll getOtherCons(ll currCost, ll totalCost) {
    ll res = 0;

    int i = -1;
    ll sub = 0;
    while(currCost > 0) {
        i++;
        sub = min(range[i] * price[i], currCost);
        currCost -= sub;
        totalCost -= sub;
    }

    int amtLeft = range[i] - sub / price[i];

    while(totalCost > 0) {
        sub = min(amtLeft * price[i], totalCost);

        res += sub / price[i];
        totalCost -= sub;

        ++i;
        amtLeft = range[i];
    }

    return res;
}

ll fromCost(ll a) {
    ll res = 0;

    int i = 0;
    while(a > 0) {
        ll sub = min(range[i] * price[i], a);
        res += sub / price[i];
        a -= sub;
        i++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(true) {
        ll totalCost;
        ll diff;
        cin >> totalCost >> diff;

        if(!totalCost && !diff) break;

        ll low = 0;
        ll high = fromCost(totalCost) / 2;
        while(1) {
            ll mid = (low + high + 1) / 2;
            ll myC = getCost(mid);
            ll otherC = getCost(getOtherCons(myC, totalCost));
            ll currDiff = otherC - myC;

            if(myC > otherC)
                high = mid;
            else if (currDiff > diff)
                low = mid;
            else if (currDiff < diff)
                high = mid;
            else
                break;
        }
        cout << getCost((low + high + 1) / 2) << endl;

    }

    return 0;
}

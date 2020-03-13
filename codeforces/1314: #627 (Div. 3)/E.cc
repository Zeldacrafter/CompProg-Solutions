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
#define ge(a, b) get<(b)>((a))
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

int dp[2010][2010];
int a[2010];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    CLR(dp, -1);

    int n, h, l, r, k;
    cin >> n >> h >> l >> r;

    F0R(i, n) {
        cin >> k;
        a[i + 1] = a[i] + k; 
    }

    F0R(i, n + 1)
        dp[0][i] = i ? -10000 : 0;

    FOR(ind, 1, n + 1) {
        FOR(early, 0, n + 1) {
            int t = (a[ind] - early + early*h) % h;
            dp[ind][early] = max(dp[ind - 1][early], dp[ind - 1][early - 1]) 
                             + (t <= r && t >= l);
        }
    }

    int res = 0;
    F0R(i, n + 1)
        ckmax(res, dp[n][i]);

    cout << res << endl;
}

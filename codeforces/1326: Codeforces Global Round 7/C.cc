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

const ll MOD = 998244353LL;

inline ll gaus(ll n) { return n * (n + 1) / 2; }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vi p(n);
    int l = -1;
    int r = -1;
    F0R(i, n) {
        cin >> p[i];
        if(p[i] > n - k) {
            r = i;
            if(l == -1)
                l = i;
        }
    }

    ll amt = 1;
    F0R(i, n) {
        if(p[i] <= n - k && i > l && i < r) {
            int cnt = 1;
            while(i + cnt < n && p[i + cnt] <= n - k)
                cnt++;
            
            amt = (amt * (cnt + 1)) % MOD;
            i = i + cnt - 1;
        }
    }
    cout << gaus(n) - gaus(n - k) << ' ' << amt << endl;
}


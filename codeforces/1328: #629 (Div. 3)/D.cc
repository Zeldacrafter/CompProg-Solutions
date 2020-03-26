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
template <typename t> bool ckmin(t& a, const t& b) {return a > b ? a = b, true : false;}
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

void solve() {
    int n;
    cin >> n;

    vi t(n), c(n);
    F0R (i, n)
        cin >> t[i];

    int maxC = 1;
    int last = -1;

    c[0] = 1;
    FOR (i, 1, n) {
        if (t[i - 1] == t[i]) {
            c[i] = c[i - 1];
            last = i;
        } else {
            c[i] = !(c[i - 1] - 1) + 1;
            maxC = 2;
        }
    }
    if(c[n - 1] == 1 && t[n - 1] != t[0]) {
        if(last == -1) {
            c[n - 1] = 3;
            maxC = 3;
        } else {
            FOR(i, last, n)
                c[i] = !(c[i] - 1) + 1;
        }
    }

    cout << maxC << endl;
    F0R (i, n)
        cout << c[i] << " \n"[i == n - 1];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while (tc--) solve();
}


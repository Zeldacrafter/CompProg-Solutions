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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k, x, y;
    cin >> n >> m >> k;
    vii start(k), end(k);
    F0R(i, k) {
        cin >> x >> y;
        start.eb(x, y);
    }
    F0R(i, k) {
        cin >> x >> y;
        end.eb(x, y);
    }
    
    if(n == 1 && m == 1) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = m*n + m + n - 3;
    assert(cnt <= n*m*2);
    cout << cnt << endl;
    
    F0R(i, m - 1)
        cout << 'R';
    F0R(i, n - 1)
        cout << 'U';

    bool down = true;
    F0R(j, m) {
        F0R(i, n - 1)
            cout << (down ? 'D' : 'U');
        if(j != m - 1)
            cout << 'L';
        down = !down;
    }

}



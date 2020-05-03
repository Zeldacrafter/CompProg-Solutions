#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }

const int MAXQ = 1e4;
const int INF = 1e9;

bitset<26> seen;
void solve() {
    seen.reset();
    vii high(26);
    F0R(i, 26)
        high[i] = mp(INF, i);

    int u;
    cin >> u;

    F0R(i, MAXQ) {
        string q, r;
        cin >> q >> r;

        assert(q != "-1"); // Cannot solve set 3

        if(SZ(q) > SZ(r))
            continue;
        
        ckmin(high[r[0] - 'A'].fi, q[0] - '0');
        for(char c : r)
            seen[c - 'A'] = true;
    }

    string res;
    F0R(i, 26)
        if(seen[i] && high[i].fi == INF) {
            res.pb(i + 'A'); 
            break;
        }
    
    sort(ALL(high));

    F0R(i, 9)
        res.pb(high[i].se + 'A');
    cout << res << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}


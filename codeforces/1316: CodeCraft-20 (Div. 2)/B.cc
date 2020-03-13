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
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

int n;
string doRev(string inp, int k) {
    string s(inp);
    F0R(i, n)
        s[i] = inp[(i + k) % n];
    if((n - k) & 1)
        reverse(s.begin() + (n - k), s.end());
    return s;
}

void solve() {
    string s;
    cin >> n >> s;

    char minChar = 'z';
    vi mins;
    FOR(i, 0, n) {
        if(s[i] == minChar)
            mins.pb(i);
        else if(s[i] < minChar) {
            minChar = s[i];
            mins.clear();
            mins.pb(i);
        }
    }

    assert(minChar <= 'z' && minChar >= 'a');
    assert(SZ(mins) > 0);

    string best = doRev(s, mins[0]);
    int bestK = mins[0];

    FOR(i, 1, SZ(mins)) {
        string resS = doRev(s, mins[i]);
        if(resS < best) {
            bestK = mins[i];
            best = resS;
        }
    }
    
    cout << best << endl << bestK + 1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();

    return 0;
}

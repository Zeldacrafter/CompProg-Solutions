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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = SZ(s);

    int l = 0;
    int r = n - 1;

    vi ls;
    vi rs;
    while(l < r) {
        while(l < r && s[l] != '(') l++;
        while(l < r && s[r] != ')') r--;
        if(l >= r) break;
        ls.pb(l++);
        rs.pb(r--);
    }


    if(!SZ(ls)) {
        cout << "0" << endl;
        return 0;
    }

    cout << 1 << endl << SZ(ls) + SZ(rs) << endl;
    
    F0R(i, SZ(ls))
        cout << ls[i] + 1 << ' ';
    R0F(i, SZ(rs) - 1)
        cout << rs[i] + 1 << " \n"[n == 0];
}

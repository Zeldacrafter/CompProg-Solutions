#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define eb emplace_back
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

bitset<200000> l, r, seen;
void solve() {
    l.reset();
    r.reset();
    int n;
    cin >> n;

    vi a(n);
    F0R(i, n)
        cin >> a[i];

    seen.reset();
    for(int i = 0, m = 0; i < n; ++i) {
        ckmax(m, a[i]);
        if(seen[a[i]])
            break;
        seen[a[i]] = true;
        l[i] = i + 1 == m;
    }
    seen.reset();
    for(int i = n - 1, m = 0; ~i ; --i) {
        ckmax(m, a[i]);
        if(seen[a[i]])
            break;
        seen[a[i]] = true;
        r[i] = n - i == m;
    }

    vii res;
    F0R(i, n - 1)
        if(l[i] && r[i + 1])
            res.eb(i + 1, n - i - 1);

    cout << SZ(res) << endl;
    for(auto [a, b] : res)
        cout << a << ' ' << b << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


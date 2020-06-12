#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, m;
    cin >> n >> m;

    vvi a(n, vi(m));
    F0R(i, n)
        F0R(j, m)
            cin >> a[i][j];

    vvi lists(n+m-1);
    F0R(i, n) 
        F0R(j, m)
            lists[i + j].pb(a[i][j]);

    int cnt = 0;
    for(int f = 0, b = SZ(lists) - 1; f < b; f++, b--) {
        int sum = accumulate(ALL(lists[f]), 0) + accumulate(ALL(lists[b]), 0);
        cnt += min(sum, SZ(lists[f]) + SZ(lists[b]) - sum);
    }
    cout << cnt << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


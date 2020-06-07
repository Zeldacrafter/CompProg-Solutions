#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, m;
    cin >> n >> m;

    vvi a(n, vi(m));
    F0R(i, n) F0R(j, m) cin >> a[i][j];

    vi row(n, true), col(m, true);
    F0R(i, n) F0R(j, m) if(a[i][j]) row[i] = col[j] = false;

    int cnt = min(accumulate(ALL(row), 0), accumulate(ALL(col), 0));
    cout << (cnt % 2 ? "Ashish" : "Vivek") << endl;
    
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


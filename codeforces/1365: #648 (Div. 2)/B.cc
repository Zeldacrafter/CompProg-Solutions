#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    cin >> n;

    vi a(n), b(n);
    F0R(i, n) cin >> a[i];
    F0R(i, n) cin >> b[i];

    int amt = accumulate(ALL(b), 0);
    cout << (is_sorted(ALL(a)) || (amt && amt < n) ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


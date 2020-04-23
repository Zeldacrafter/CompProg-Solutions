// this line is here for a reason
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n), p(n, 0);
    F0R(i, n)
        cin >> a[i];

    FOR(i, 1, n - 1)
        p[i] = p[i - 1] + (a[i - 1] < a[i] && a[i + 1] < a[i]);

    int bestL = 0, best = 0;
    F0R(i, n - k + 1)
        if(ckmax(best, p[i + k - 2] - p[i]))
            bestL = i;
    cout << best + 1 << ' ' <<  bestL + 1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}



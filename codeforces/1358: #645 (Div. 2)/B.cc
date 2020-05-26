#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    cin >> n;

    vi a(n);
    F0R(i, n) cin >> a[i];

    sort(ALL(a));

    int best = 0;
    F0R(i, n)
        if(a[i] <= i + 1)
            best = i + 1;
    cout << best + 1 << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


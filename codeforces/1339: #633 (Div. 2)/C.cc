#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    F0R(i, n)
        cin >> a[i];

    int maxTime = 0;
    FOR(i, 1, n) {
        if(a[i - 1] <= a[i])
            continue;
        ckmax(maxTime, 32 - __builtin_clz(a[i - 1] - a[i]));
        a[i] = a[i - 1];
    }
    cout << maxTime << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


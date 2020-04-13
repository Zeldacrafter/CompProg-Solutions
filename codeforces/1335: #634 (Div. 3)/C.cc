#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

void solve() {
    int n, k;
    cin >> n;

    int dist = 0;
    vi skillC(n);
    F0R(i, n) {
        cin >> k;
        if(!skillC[--k]++) 
            dist++;
    }

    int maxC = 0;
    F0R(i, n)
        ckmax(maxC, skillC[i]);

    cout << max({min(maxC, dist - 1), min(maxC - 1, dist), 0}) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


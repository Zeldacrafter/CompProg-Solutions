#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

const int MAXN = 2e5;
bitset<MAXN> seen;
vi p, c, cycle;

bool valid(int step) {
    F0R(start, step) {
        int color = c[cycle[start]];
        bool ok = true;
        for(int j = start; ok && j < SZ(cycle); j += step)
            if(c[cycle[j]] != color)
                ok = false;
        if(ok)
            return true;
    }
    return false;
}

void solve() {
    seen.reset();

    int n;
    cin >> n;

    p = vi(n);
    c = vi(n);
    F0R(i, n)
        cin >> p[i], p[i]--;
    F0R(i, n)
        cin >> c[i], c[i]--;

    int res = 1e9;
    F0R(i, n) {
        if(seen[i]) continue;

        cycle.clear();
        int len = 0;
        int curr = i;
        while(!seen[curr]) {
            seen[curr] = true;
            cycle.pb(curr);
            curr = p[curr];
            ++len;
        }

        for(int j = 1; j*j <= len; ++j) {
            if(len % j) continue;

            if(res > len/j && valid(len/j))
                res = len/j;
            if(res > j && valid(j))
                res = j;
        }
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


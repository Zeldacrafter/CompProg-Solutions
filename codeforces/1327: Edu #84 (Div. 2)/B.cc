#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

bitset<(int)1e5 + 5> taken;
void solve() {
    taken.reset();
    int n, k, g;
    cin >> n;

    int improv = -1;
    FOR(i, 1, n + 1) {
        cin >> k;

        bool ok = false;
        F0R(j, k) {
            cin >> g;

            if(!ok && !taken[g]) {
                ok = true;
                taken[g] = true;
            }
        }
        if(!ok)
            improv = i;
    }

    if(improv == -1) {
        cout << "OPTIMAL\n";
        return;
    }

    FOR(i, 1, n + 1)
        if(!taken[i]) {
            cout << "IMPROVE\n" << improv << ' ' << i << endl;
            return;
        }

    cout << "OPTIMAL\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vi l(n);
    F0R(i, m) 
        cin >> l[i];

    vi need(m);
    need[m - 1] = l[m - 1];
    R0F(i, m - 2)
        need[i] = max(need[i + 1] + 1, l[i]);

    if(need[0] > n) {
        cout << -1 << endl;
        return 0;
    }

    vi pos(m);
    int colored = 0;
    F0R(i, m) {
        pos[i] = min(colored, n - need[i]);
        colored = pos[i] + l[i];
    }

    if(colored != n)
        cout << -1 << endl;
    else
        F0R(i, m)
            cout << pos[i] + 1 << " \n"[i == m - 1];
}

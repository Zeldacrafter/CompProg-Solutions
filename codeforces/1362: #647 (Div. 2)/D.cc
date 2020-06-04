#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for(int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vvi todo(n);
    for(int i = 0, k; i < n; ++i) {
        cin >> k;
        todo[k - 1].pb(i);
    }

    vi lowest(n, -1), res;
    F0R(t, n) {
        for(int k : todo[t]) {
            if(lowest[k] != t - 1) {
                cout << -1 << endl;
                return 0;
            }
            for(int v : adj[k])
                if(lowest[v] == t - 1)
                    lowest[v] = t;
            res.pb(k);
        }
    }
    for(int r : res)
        cout << r + 1 << ' ';
}



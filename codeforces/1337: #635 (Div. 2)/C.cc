#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

vii dist;
vvi adj;

void dfs(int v = 0, int p = -1) {
    int cnt = 0;
    for(int u : adj[v]) {
        if(u == p) continue;
        dist[u].fi = dist[v].fi + 1;
        dfs(u, v);
        cnt += 1 + dist[u].se;
    }
    dist[v].se = cnt;
}

void solve() {
    int n, k, u, v;
    cin >> n >> k;

    adj = vvi(n);
    F0R(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dist = vii(n);
    dfs();

    sort(ALL(dist), [&](ii a, ii b) { return a.se - a.fi < b.se - b.fi; });

    ll res = 0;
    F0R(i, k)
        res += dist[i].fi - dist[i].se;
    cout << res << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}


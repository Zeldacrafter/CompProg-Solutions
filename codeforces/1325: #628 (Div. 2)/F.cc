#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define ge(a, b) get<(b)>((a))
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define CLR(a, b) memset((a), (b), sizeof((a)))

vvi adj;
int sq;
bitset<100010> inSet;
int depth[100010];
vi path;

void dfs(int v) {
    path.pb(v);
    depth[v] = SZ(path);

    for(int u : adj[v]) {
        if(depth[u] == -1)
            dfs(u);
        else if(depth[v] - depth[u] >= sq - 1) {
            cout << 2 << endl
                 << depth[v] - depth[u] + 1 << endl;
            FOR(i, depth[u] - 1, depth[v])
                cout << path[i] + 1 << ' ';
            exit(0);
        }
    }

    if(inSet[v])
        for(int u : adj[v])
            inSet[u] = false;

    path.pop_back();
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    sq = (int)ceil(sqrt(1.0*n));

    adj = vvi(n);
    F0R(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    CLR(depth, -1);
    inSet.flip();
    dfs(0);

    cout << 1 << endl;
    for(int i = 0; sq; ++i) {
        if(inSet[i]) {
            cout << i + 1 << ' ';
            sq--;
        }
    }
}



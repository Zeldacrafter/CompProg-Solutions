#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

vi height;
vi eularianTour;
vi first;
vvi adj;
const int MAXN = 1e6, K = 24;
int st[MAXN + 1][K + 1];
void sparsePre() {
    F0R (i, SZ(eularianTour))
        st[i][0] = eularianTour[i];
    FOR (j, 1, K + 1) {
        for (int i = 0; i + (1 << j) <= SZ(eularianTour); ++i)
            if (height[st[i][j - 1]] < height[st[i + (1 << (j - 1))][j - 1]])
                st[i][j] = st[i][j - 1];
            else
                st[i][j] = st[i + (1 << (j - 1))][j - 1];
    }
}
int rmq(int a, int b) {
    int j = 31 - __builtin_clz(b - a + 1);
    if (height[st[a][j]] < height[st[b - (1 << j) + 1][j]]) return st[a][j];
    return st[b - (1 << j) + 1][j];
}
void dfs(int v = 0, int h = 0) {
    eularianTour.pb(v);
    first[v] = SZ(eularianTour) - 1;
    height[v] = h;
    for (int u : adj[v]) {
        if (first[u] == -1) {
            dfs(u, h + 1);
            eularianTour.pb(v);
        }
    }
}
void lcaPre(int root = 0) {
    height.assign(SZ(adj), -1);
    first.assign(SZ(adj), -1);
    dfs(root);
    sparsePre();
}
int lca(int a, int b) {
    return rmq(min(first[a], first[b]), max(first[a], first[b]));
}

vi parent;
void root(int v = 0) {
    for(int u : adj[v]) {
        if(parent[u] != -1)
            continue;
        parent[u] = v;
        root(u);
    }
}

void solve() {
    int k;
    cin >> k;

    vi vs(k);
    F0R(i, k)
        cin >> vs[i], vs[i]--;

    int deepest = vs[0];
    for(int v : vs)
        if(height[v] > height[deepest])
            deepest = v;
    
    for(int v : vs) {
        int u = lca(v, deepest);
        if(u != parent[v] && u != v) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, u, v;
    cin >> n >> m;
    
    adj = vvi(n);

    F0R(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    parent = vi(n, -1);
    root();
    lcaPre();

    while(m--)
        solve();
}


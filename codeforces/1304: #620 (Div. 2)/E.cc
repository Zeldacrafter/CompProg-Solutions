#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define SZ(x) (x).size()
#define pb push_back
#define eb emplace_back

vector<vi> adj;
vi inPath;

vi path;
vi h;
bitset<100010> seen;
void createPath(int u, int height) {
    path.pb(u);
    h.pb(height);
    inPath[u] = SZ(path) - 1;
    
    for(int v : adj[u])
        if(!seen[v]) {
            seen[v] = true;
            createPath(v, height + 1);
            path.pb(u);
            h.pb(height);
        }
}

int spT[1000010][17];
void buildTable() {
    int n = SZ(path);
    F0R(i, n)
        spT[i][0] = h[i];

    for(int j = 1; (1 << j) <= n; ++j)
        for(int i = 0; i + (1 << j) <= n; ++i)
            spT[i][j] = min(spT[i][j - 1], spT[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
    if(l > r) swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return min(spT[l][k], spT[r - (1 << k) + 1][k]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    adj = vector<vi>(n);
    F0R(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    inPath = vi(n);
    seen[0] = true;
    createPath(0, 1);
    buildTable();

    int tc;
    cin >> tc;
    while(tc--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--; y--; a--; b--;

        x = inPath[x];
        y = inPath[y];
        a = inPath[a];
        b = inPath[b];

        int d1 = h[a] + h[b] - 2*query(a, b);
        int d2 = h[a] + h[y] - 2*query(a, y) + h[b] + h[x] - 2*query(b, x) + 1;
        int d3 = h[a] + h[x] - 2*query(a, x) + h[b] + h[y] - 2*query(b, y) + 1;
        if((d1 <= k && (d1 & 1) == (k & 1)) ||
           (d2 <= k && (d2 & 1) == (k & 1)) ||
           (d3 <= k && (d2 & 1) == (k & 1)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

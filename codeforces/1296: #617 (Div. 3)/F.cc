#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define RALL(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

int p[5000][5000];
vvii adj;
bitset<5001> seen;

void dfs(int v, int next, int from) {
    for(auto [u, i] : adj[v]) {
        if(seen[u]) continue;

        seen[u] = true;
        p[from][u] = next;
        dfs(u, next, from);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x, y, m, a, b, s;
    cin >> n;
    
    vii railways(n);
    adj = vvii(n);
    F0R(i, n - 1) {
        cin >> x >> y;
        x--; y--;
        adj[x].eb(y, i);
        adj[y].eb(x, i);
        railways[i] = mp(x, y);
    }

    F0R(i, n) {
        p[i][i] = i;
        seen.reset();
        seen[i] = true;
        for(auto [v, j] : adj[i]) {
            p[i][v] = j;
            dfs(v, j, i);
        }
    }
   
    cin >> m;
    vector<tuple<int, int, int>> paths(m);
    F0R(i, m) {
       cin >> a >> b >> s;
       a--; b--;
       paths[i] = mt(s, a, b);
    }

    sort(RALL(paths));

    vi res(n - 1, 0);
    for(auto [s, x, y] : paths) {
        int curr = x;
        while(curr != y) {
            ckmax(res[p[curr][y]], s);

            auto [xx, yy] = railways[p[curr][y]];
            assert(xx == curr || yy == curr);
            if(xx == curr)
                curr = yy;
            else
                curr = xx;
            
        }
    }
    
    for(auto [s, x, y] : paths) {
        bool found = false;

        int curr = x;
        while(curr != y) {
            if(res[p[curr][y]] == s) {
                found = true;
                break;
            }

            auto [xx, yy] = railways[p[curr][y]];
            assert(xx == curr || yy == curr);
            if(xx == curr)
                curr = yy;
            else
                curr = xx;
            
        }

        if(!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    F0R(i, n - 1)
        if(!res[i])
            res[i] = 1e6;

    F0R(i, n - 1)
        cout << res[i] << " \n"[i == n - 2];

}


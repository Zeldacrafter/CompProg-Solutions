#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define pb push_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

bitset<200010> seen;
int dist[200010] = {};
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k, a, b;
    cin >> n >> m;

    vvi adj(n);
    vvi adjB(n);
    F0R(i, m) {
        cin >> a >> b;
        a--; b--;
        adjB[b].pb(a);
        adj[a].pb(b);
    }

    cin >> k;
    vi path;
    F0R(i, k) {
        cin >> a;
        a--;
        path.pb(a);
    }

    queue<ii> q;
    q.emplace(path[k - 1], 0);
    seen[path[k - 1]] = true;
    while(!q.empty()) {
        auto [v, d] = q.front();
        q.pop();
        dist[v] = d;
        for(int u : adjB[v]) {
            if(!seen[u]) {
                q.emplace(u, d + 1);
                seen[u] = true;
            }
        }
    }

    int minRes = 0;
    int maxRes = 0;
    F0R(i, k - 1) {
        int curr = path[i];
        int next = path[i + 1];
        
        if(dist[next] != dist[curr] - 1) {
            minRes++;
            maxRes++;
            continue;
        }
        
        bool found = false;
        for(int v : adj[curr]) {
            if(v != next && dist[v] == dist[curr] - 1) {
                found = true;
                break;
            }
        }

        if(found)
            maxRes++;
    }

    cout << minRes << ' ' << maxRes << endl;
}

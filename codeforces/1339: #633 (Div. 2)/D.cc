#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a, b;
    cin >> n;

    vvi adj(n);
    F0R(i, n - 1) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int maxC = n - 1;
    set<int> seen;
    vi d(n, -1);
    queue<int> q;
    F0R(i, n)
        if(SZ(adj[i]) == 1) {
            if(seen.count(adj[i][0]))
                maxC--;
            else
                seen.insert(adj[i][0]);
            q.push(i);
            d[i] = 0;
        }

    bool allEven = true;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int i : adj[curr]) {
            if(d[i] != -1) {
                int len = d[i] + d[curr] + 1;
                if(len > 1 && len & 1)
                    allEven = false;
                continue;
            }
            d[i] = d[curr] + 1;
            q.push(i);
        }
    }

    cout << (allEven ? 1 : 3) << ' ' << maxC << endl;
}



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pf push_front
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ge(a, b) get<(b)>((a))
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

bitset<100010> seen;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vii edges(n - 1);
    vvii adj(n);
    F0R(i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        edges[i] = mp(x, y);
        adj[x].eb(y, i);
        adj[y].eb(x, i);
    }


    queue<int> q;
    F0R(i, n) {
        if(SZ(adj[i]) == 1) {
            seen[i] = true;
            q.push(i);
        }
    }

    int cnt = 0;
    vi res(n - 1, -1);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto [x, i] : adj[curr]) {
            if(res[i] != -1) continue;

            res[i] = cnt++;

            if(seen[x]) continue;
            seen[x] = true;
            q.push(x);
        }
    }

    F0R(i, n - 1)
        cout  << res[i] << endl;

}


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

bitset<200010> white;
int score[200010], par[200010];
vvi adj;

int dfs(int v) {
    int cnt = white[v] ? 1 : -1;

    for(int u : adj[v]) {
        if(u == par[v]) continue;
        par[u] = v;
        int s = dfs(u);
        if(s > 0) cnt += s;
    }
    score[v] = cnt;
    return cnt;
}

void dfs2(int v) {
    if(par[v] != -1) {
        if(score[v] > 0)
            ckmax(score[v], score[par[v]]);
        else
            ckmax(score[v], score[v] + score[par[v]]);
    }
    for(int u : adj[v])
        if(u != par[v])
            dfs2(u);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a, b;
    cin >> n;

    FOR(i, 1, n + 1) {
        cin >> a;
        white[i] = a;
    }

    adj = vvi(n + 1);
    F0R(i, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    par[1] = -1;
    dfs(1);
    dfs2(1);

    FOR(i, 1, n + 1) 
        cout << score[i] << " \n"[i == n];
}


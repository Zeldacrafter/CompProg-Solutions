#include "../utils.cc"

typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;

void solve() {
    map<string, int> idx;
    vi flow, pos;
    vvi adj;

    auto getIdx = [&](string& s) {
        if(!idx.count(s)) {
            idx[s] = SZ(flow);
            flow.pb(0);
            pos.pb(-1);
            adj.eb();
        }
        return idx[s];
    };

    int start = -1, npos = 0;
    getInp([&](auto& cin, int) {
        int f; string from, to(2, '?'); char c;
        cin >> from >> f >> to[0] >> to[1];

        int fromIdx = getIdx(from);

        flow[fromIdx] = f;
        if(from == "AA") start = fromIdx;
        if(f) pos[fromIdx] = npos++;
        
        do {
            int toIdx = getIdx(to);
            adj[fromIdx].pb(toIdx);
        } while(cin >> c >> to[0] >> to[1]);
    }, "Valve ([A-Z]*) has flow rate=([0-9]*); tunnels? leads? to valves? (.*)");
    assert(~start);

    const int n = SZ(adj);

    vvvvi dp(27, vvvi(n, vvi(n, vi(1 << npos, -1))));
    dp[0][start][start][0] = 0;
    F0R (i, 26) F0R (j, n) F0R (k, n) F0R (l, 1 << npos) {
        if (!~dp[i][j][k][l]) continue;

        vector<tuple<int, int, int>> a, b;

        if (~pos[j] && !((l >> pos[j]) & 1))
            a.eb(j, l | (1 << pos[j]), (26 - i - 1) * flow[j]);
        for (int u : adj[j]) a.eb(u, l, 0);

        if (k != j && ~pos[k] && !((l >> pos[k]) & 1))
            b.eb(k, l | (1 << pos[k]), (26 - i - 1) * flow[k]);
        for (int u : adj[k]) b.eb(u, l, 0);
        
        for (auto [c1, o1, v1] : a)
            for (auto [c2, o2, v2] : b)
                ckmax(dp[i + 1][c1][c2][o1 | o2], dp[i][j][k][l] + v1 + v2);
    }
    int best = 0;
    F0R (j, n) F0R (k, n) F0R (l, 1 << npos) ckmax(best, dp[26][j][k][l]);
    cout << best << endl;

}


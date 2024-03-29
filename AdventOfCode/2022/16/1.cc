#include "../utils.cc"

typedef vector<vvi> vvvi;


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

    vvvi dp(31, vvi(n, vi(1 << npos, -1)));
    dp[0][start][0] = 0;
    F0R(i, 30) F0R(j, n) F0R(k, 1 << npos) {
        if (dp[i][j][k] == -1) continue;
        if (~pos[j] && !((k >> pos[j]) & 1))
            ckmax(dp[i + 1][j][k | (1 << pos[j])], dp[i][j][k] + (30 - i - 1) * flow[j]);
        for (int u : adj[j])
            ckmax(dp[i + 1][u][k], dp[i][j][k]);
    }

    int best = 0;
    F0R (j, n) F0R (k, 1 << npos) ckmax(best, dp[26][j][k]);
    cout << best << endl;
}


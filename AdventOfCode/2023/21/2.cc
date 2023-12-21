#include "../utils.cc"

const vi dr {0, 0, -1, 1}, dc {-1, 1, 0, 0};
const int AMT = 26501365;

int sgn(ll x) { return (x > 0) - (x < 0); }

void solve() {
    vector<string> ss = getInp();
    assert(SZ(ss) == SZ(ss[0]));
    int N = SZ(ss);

    ii start;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0])) if(ss[i][j] == 'S') start = mp(i, j);

    // r, c, loopR, loopC, t
    queue<tuple<int, int, int, int>> q;
    map<tuple<int, int, int, int>, ll> dist;

    q.emplace(start.fi, start.se, 0, 0);
    dist[{start.fi, start.se, 0, 0}] = 0;

    while(SZ(q)) {
        auto [r, c, loopR, loopC] = q.front();
        q.pop();

        F0R(i, 4) {
            int rr = r + dr[i], cc = c + dc[i],
                loopRR = loopR, loopCC = loopC;

            if(rr < 0) --loopRR;
            if(rr >= N) ++loopRR;
            if(cc < 0) --loopCC;
            if(cc >= N) ++loopCC;
            rr = ((rr % N) + N) % N;
            cc = ((cc % N) + N) % N;

            tuple<int, int, int, int> t(rr, cc, loopRR, loopCC);
            if(ss[rr][cc] == '#' || max(abs(loopRR), abs(loopCC)) > 5 
                                 || dist.count(t))
                continue;
            dist[t] = dist[{r, c, loopR, loopC}] + 1;
            q.push(t);
        }
    }

    auto calc = [&](int d, bool isCorner) {
        static map<pair<int, bool>, ll> dp;
        int grids = (AMT-d)/N;
        if(dp.count({d, isCorner})) return dp[{d, isCorner}];
        ll res = 0;
        FOR(x, 1, grids + 1)
            if(d + N*x <= AMT && (d + N*x) % 2 == (AMT % 2))
                res += isCorner*x + 1;
        return dp[{d, isCorner}] = res;
    };

    ll res = 0;
    F0R(r, N) F0R(c, N) {
        if(ss[r][c] == '#') continue;

        // Calculate how often we can reach (r, c)
        // in the repeating grids.
        FOR(loopR, -3, 4) FOR(loopC, -3, 4) {
            ll d = dist[{r, c, loopR, loopC}];
            if(d % 2 == AMT % 2 && d <= AMT) ++res;
            if(abs(loopR) == 3 && abs(loopC) == 3)
                res += calc(d, true); // Corner
            else if(abs(loopR) == 3 || abs(loopC) == 3)
                res += calc(d, false); // Edge
        }
    }
    cout << res << endl;
}

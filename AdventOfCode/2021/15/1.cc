#include "../utils.cc"

vi dr{1, -1, 0, 0}, dc{0, 0, 1, -1};

void solve() {
    vector<string> ss = getInp();
    F0R(i, SZ(ss)) F0R(j, SZ(ss[i])) ss[i][j] -= '0';

    vvi dist(SZ(ss), vi(SZ(ss[0]), 1e9));
    dist[0][0] = 0;

    set<tuple<ll, int, int>> q;
    q.emplace(0, 0, 0);
    while(SZ(q)) {
        auto [d, r, c] = *q.begin();
        q.erase(q.begin());
        if(dist[r][c] < d) continue;

        F0R(i, 4) {
            int rr = r + dr[i], cc = c + dc[i];
            if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0]))
                continue;
            int val = d + ss[rr][cc];
            if(ckmin(dist[rr][cc], val))
                q.emplace(val, rr, cc);
        }
    }
    cout << dist.back().back() << endl;
}

#include "../utils.cc"

const vi dr {0, 0, -1, 1}, dc {-1, 1, 0, 0};
const int N = 64;

void solve() {
    vector<string> ss = getInp();

    ii start;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0])) if(ss[i][j] == 'S') start = mp(i, j);

    queue<tuple<int, int, int>> q;
    set<tuple<int, int, int>> seen;

    q.emplace(start.fi, start.se, 0);
    seen.emplace(start.fi, start.se, 0);

    while(SZ(q)) {
        auto [r, c, t] = q.front();
        q.pop();

        if(t == N + 1) break;

        F0R(i, 4) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0])) continue;

            if(ss[rr][cc] == '#') continue;

            if(seen.emplace(rr, cc, t + 1).se)
                q.emplace(rr, cc, t + 1);
        }
    }

    ll res = 0;
    for(auto [r, c, t] : seen)
        res += t == N;
    cout << res << endl;
}


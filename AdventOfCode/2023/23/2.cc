#include "../utils.cc"

ll res = 0;
ii start, goal;
vector<string> ss;
map<ii, vector<pair<ii, int>>> adj;

const vi dr {0, 0, -1, 1}, dc {-1, 1, 0, 0};

void dfs(ii pos = start, ll d = 0) {
    static set<ii> seen;
    if(pos == goal) {
        ckmax(res, d);
        return;
    }

    if(seen.count(pos)) return;

    seen.insert(pos);
    for(auto [p, dist] : adj[pos]) dfs(p, d + dist);
    seen.erase(pos);
}

void solve() {
    ss = getInp();
    
    start = mp(0, 1);
    goal = mp(SZ(ss)-1, SZ(ss[0])-2);

    auto isSplit = [&](int r, int c) {
        if(mp(r, c) == start || mp(r, c) == goal) return true;

        return ss[r][c] == '.' && 
            ss[r - 1][c] != '.' && ss[r + 1][c] != '.' &&
            ss[r][c - 1] != '.' && ss[r][c + 1] != '.';
    };

    F0R(rS, SZ(ss)) F0R(cS, SZ(ss[0])) {
        if(!isSplit(rS, cS)) continue;

        set<ii> seen;
        queue<tuple<int, int, int>> q;
        q.emplace(rS, cS, 0);
        seen.emplace(rS, cS);

        while(SZ(q)) {
            auto [r, c, d] = q.front();
            q.pop();

            F0R(i, 4) {
                int rr = r + dr[i],
                    cc = c + dc[i];

                if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0]) 
                        || ss[rr][cc] == '#' 
                        || seen.count({rr, cc}))
                    continue;

                if(isSplit(rr, cc)) {
                    adj[mp(rS, cS)].eb(mp(rr, cc), d + 1);
                } else {
                    seen.emplace(rr, cc);
                    q.emplace(rr, cc, d + 1);
                }
            }
        }
    }

    dfs();
    cout << res << endl;
}


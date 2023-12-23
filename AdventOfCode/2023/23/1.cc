#include "../utils.cc"

ll res = 0;
ii start, goal;
vector<string> ss;

const vii dPos {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0)};
map<ii, char> allowed { {mp(1, 0), 'v'}, {mp(-1, 0), '^'}, {mp(0, 1), '>'}, {mp(0, -1), '<'} };

void dfs(ii pos = start, ll d = 0) {
    static set<ii> seen;
    if(pos == goal) {
        ckmax(res, d);
        return;
    }

    seen.insert(pos);

    F0R(i, 4) {
        ii newPos = pos + dPos[i];
        auto [rr, cc] = newPos;

        if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0])
            || (ss[rr][cc] != '.' && allowed[dPos[i]] != ss[rr][cc])
            || seen.count(newPos))
            continue;

        dfs(newPos, d + 1);
    }

    seen.erase(pos);
}

void solve() {
    ss = getInp();
    start = mp(0, 1);
    goal = mp(SZ(ss)-1, SZ(ss[0])-2);

    dfs();
    cout << res << endl;
}


#include "../utils.cc"

vii mv = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void solve() {
    vector<string> ss = getInp();

    ii start;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0])) if(ss[i][j] == '^') start = mp(i, j);

    auto in = [&](ii p) {
        return p.fi >= 0 && p.se >= 0 && p.fi < SZ(ss) && p.se < SZ(ss[0]);
    };

    auto loop = [&]() {
        ii pos = start;
        int dir = 0;
        set<pair<ii, int>> seen;

        while(in(pos)) {
            if(seen.contains({pos, dir})) return true;
            seen.emplace(pos, dir);
            
            ii newPos = pos + mv[dir];
            while(in(newPos) && ss[newPos.fi][newPos.se] == '#') {
                dir = (dir + 1) % 4;
                newPos = pos + mv[dir];
            }
            pos = newPos;
        }
        return false;
    };

    ll res = 0;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0])) if(ss[i][j] == '.') {
        ss[i][j] = '#';
        res += loop();
        ss[i][j] = '.';
    }
    cout << res << endl;
}


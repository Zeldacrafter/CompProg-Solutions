#include "../utils.cc"

vii mv = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void solve() {
    vector<string> ss = getInp();

    ii pos;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0])) if(ss[i][j] == '^') pos = mp(i, j);

    auto in = [&](ii p) {
        return p.fi >= 0 && p.se >= 0 && p.fi < SZ(ss) && p.se < SZ(ss[0]);
    };

    set<ii> seen;
    int dir = 0;
    while(in(pos)) {
        seen.insert(pos);

        ii newPos = pos + mv[dir];
        while(in(newPos) && ss[newPos.fi][newPos.se] == '#') {
            dir = (dir + 1) % 4;
            newPos = pos + mv[dir];
        }
        pos = newPos;
    }

    cout << SZ(seen) << endl;
}


#include "../utils.cc"

vii dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void solve() {
    vector<string> ss = getInp();

    ii start, end;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0])) {
        if(ss[i][j] == 'S') start = mp(i, j);
        if(ss[i][j] == 'E') end = mp(i, j);
    }

    auto get = [&](ii p) { return ss[p.fi][p.se]; };

    set<tuple<int, ii, int>> q;
    set<pair<ii, int>> seen;
    q.emplace(0, start, 0);
    while(SZ(q)) {
        auto [score, pos, dir] = *q.begin();
        q.erase(q.begin());

        if(pos == end) {
            cout << score << endl;
            break;
        }

        if(seen.contains(mp(pos, dir))) continue;
        seen.emplace(pos, dir);

        if(get(pos + dirs[dir]) != '#') q.emplace(score + 1, pos + dirs[dir], dir);
        q.emplace(score + 1000, pos, (dir + 1) % 4);
        q.emplace(score + 1000, pos, (dir + 3) % 4);
    }
}


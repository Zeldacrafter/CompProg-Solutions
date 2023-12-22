#include "../utils.cc"

typedef tuple<int, int, int> iii;

void solve() {
    vector<vector<iii>> bricks;
    set<iii> filled;

    int minX = 1e9, maxX = 0, minY = 1e9, maxY = 0;

    getInp([&](auto& cin, int) {
        int x1, x2, y1, y2, z1, z2; char c;
        cin >> x1 >> c >> y1 >> c >> z1 >> c
            >> x2 >> c >> y2 >> c >> z2;

        bricks.eb();
        FOR(x, x1, x2 + 1) FOR(y, y1, y2 + 1) FOR(z, z1, z2 + 1) {
            bricks.back().eb(x, y, z);
            filled.emplace(x, y, z);
        }
        ckmin(minX, x1);
        ckmax(maxX, x2);
        ckmin(minY, y1);
        ckmax(maxY, y2);
    });

    FOR(x, minX, maxX + 1) FOR(y, minY, maxY + 1)
        filled.emplace(x, y, 0);

    auto canMoveDown = [](int i, const vector<vector<iii>>& bs, const set<iii>& fs) {
        assert(i >= 0 && i < SZ(bs));

        set<iii> curr(ALL(bs[i]));
        for(iii cube : bs[i])
            if(fs.count(cube - mt(0, 0, 1)) && !curr.count(cube - mt(0, 0, 1)))
                return false;
        return true;
    };

    set<int> falling;

    auto moveDown = [&](vector<vector<iii>>& bs, set<iii>& fs) {
        bool change = false;
        F0R(i, SZ(bs)) {
            if(canMoveDown(i, bs, fs)) {
                change = true;
                falling.insert(i);
                for(iii cube : bs[i]) {
                    fs.erase(cube);
                    fs.emplace(cube - mt(0, 0, 1));
                }
                bs[i] -= mt(0, 0, 1);
            }
        }
        return change;
    };

    while(moveDown(bricks, filled));

    ll res = 0;
    F0R(i, SZ(bricks)) {
        falling = {};
        set<iii> fs(ALL(filled));
        vector<vector<iii>> bs(ALL(bricks));
        for(iii cube : bs[i]) fs.erase(cube);
        bs.erase(bs.begin() + i);

        while(moveDown(bs, fs));
        res += SZ(falling);
    }
    cout << res << endl;
}


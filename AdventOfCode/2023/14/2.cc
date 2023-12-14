#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    map<vector<string>, int> seen;
    seen[ss] = 0;
    for(int iter = 1;; ++iter) {
        F0R(_, 4) {
            vi top(SZ(ss[0]), -1);
            F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
                if(ss[r][c] == '#') top[c] = r;
                else if(ss[r][c] == 'O') {
                    ss[r][c] = '.';
                    ss[++top[c]][c] = 'O';
                }
            }

            vector<string> rot(SZ(ss[0]), string(SZ(ss), '?'));
            F0R(r, SZ(ss)) F0R(c, SZ(ss[r])) rot[c][SZ(ss) - 1 - r] = ss[r][c];
            ss = rot;
        }

        if(seen.count(ss)) {
            ll resIter = (1000000000ll - seen[ss]) % (iter - seen[ss]) + seen[ss];
            auto& grid = find_if(ALL(seen), [&](auto& p) { return p.se == resIter; })->fi;

            ll res = 0;
            F0R(r, SZ(grid))
                F0R(c, SZ(grid[r]))
                    if(grid[r][c] == 'O')
                        res += SZ(grid) - r;
            cout << res << endl;
            return;
        } 
        seen[ss] = iter;
    }
    assert(false);
}


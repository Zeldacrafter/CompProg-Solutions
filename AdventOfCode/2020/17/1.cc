#include "../template.cc"

const int OFFSET = 7;
const int MAXN = 2*OFFSET + 10;


void solve() {
    ll res = 0;
    vector<string> ss = getInp();

    vector<vector<string>> grid(MAXN, vector<string>(MAXN, string(MAXN, '.')));
    F0R(i, SZ(ss))
        F0R(j, SZ(ss[i]))
            grid[OFFSET][OFFSET + j][OFFSET + i] = ss[i][j];

    auto cntAdj = [&](int x, int y, int z) {
        int cnt = 0;
        for(int dx : {-1, 0, 1})
            for(int dy : {-1, 0, 1})
                for(int dz : {-1, 0, 1})
                    if(dx || dy || dz)
                        cnt += grid[z + dz][y + dy][x + dx] == '#';
        return cnt;
    };

    F0R(i, 6) {
        res = 0;
        vector<vector<string>> newGrid(MAXN, vector<string>(MAXN, string(MAXN, '.')));
        FOR(x, 1, MAXN - 1)
            FOR(y, 1, MAXN - 1) 
                FOR(z, 1, MAXN - 1) {
                    int cnt = cntAdj(x, y, z);
                    if(grid[z][y][x] == '#' && (cnt == 2 || cnt == 3)) {
                        res++;
                        newGrid[z][y][x] = '#';
                    } else if(grid[z][y][x] == '.' && cnt == 3) {
                        res++;
                        newGrid[z][y][x] = '#';
                    }
                }
        grid = newGrid;
    }


    cout << res << endl;
}


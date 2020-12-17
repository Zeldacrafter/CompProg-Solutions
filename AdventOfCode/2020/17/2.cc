#include "../template.cc"

const int OFFSET = 7;
const int MAXN = 2*OFFSET + 10;


void solve() {
    ll res = 0;
    vector<string> ss = getInp();

    vector<vector<vector<string>>> grid(MAXN, vector<vector<string>>(MAXN, vector<string>(MAXN, string(MAXN, '.'))));
    F0R(i, SZ(ss))
        F0R(j, SZ(ss[i]))
            grid[OFFSET][OFFSET][OFFSET + j][OFFSET + i] = ss[i][j];

    auto cntAdj = [&](int x, int y, int z, int w) {
        int cnt = 0;
        for(int dx : {-1, 0, 1})
            for(int dy : {-1, 0, 1})
                for(int dz : {-1, 0, 1})
                    for(int dw : {-1, 0, 1})
                        if(dx || dy || dz || dw)
                            cnt += grid[w + dw][z + dz][y + dy][x + dx] == '#';
        return cnt;
    };

    F0R(i, 6) {
        res = 0;
        vector<vector<vector<string>>> newGrid(MAXN, vector<vector<string>>(MAXN, vector<string>(MAXN, string(MAXN, '.'))));
        FOR(x, 1, MAXN - 1)
            FOR(y, 1, MAXN - 1) 
                FOR(z, 1, MAXN - 1) 
                    FOR(w, 1, MAXN - 1) {
                        int cnt = cntAdj(x, y, z, w);
                        if(grid[w][z][y][x] == '#' && (cnt == 2 || cnt == 3)) {
                            res++;
                            newGrid[w][z][y][x] = '#';
                        } else if(grid[w][z][y][x] == '.' && cnt == 3) {
                            res++;
                            newGrid[w][z][y][x] = '#';
                        }
                    }
        grid = newGrid;
    }


    cout << res << endl;
}


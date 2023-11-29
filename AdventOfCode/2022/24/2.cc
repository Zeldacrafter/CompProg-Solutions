#include "../utils.cc"

#define EMPTY 0
#define L (1 << 0)
#define R (1 << 1)
#define U (1 << 2)
#define D (1 << 3)
#define WALL (1 << 4)

const vi dr = {0, 0, 1, -1, 0}, dc = {-1, 1, 0, 0, 0};

void solve() {
    vector<string> ss = getInp();

    vvi grid(SZ(ss), vi(SZ(ss[0]), EMPTY));
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        if(ss[r][c] == '#') grid[r][c] = WALL;
        else if(ss[r][c] == '<') grid[r][c] = L;
        else if(ss[r][c] == '>') grid[r][c] = R;
        else if(ss[r][c] == '^') grid[r][c] = U;
        else if(ss[r][c] == 'v') grid[r][c] = D;
    }

    int currTime = 0;
    F0R(a, 3) {
        ii start = a == 1 ? mp(SZ(ss) - 1, SZ(ss[0]) - 2) : mp(0, 1);
        ii end = a != 1 ? mp(SZ(ss) - 1, SZ(ss[0]) - 2) : mp(0, 1);

        // r, c, time
        set<tuple<int, int, int>> seen;
        queue<tuple<int, int, int>> q;
        q.emplace(start.fi, start.se, currTime);
        seen.emplace(start.fi, start.se, currTime);

        while(!q.empty()) {
            auto [r, c, t] = q.front();
            q.pop();

            if(mp(r, c) == end)
                break;

            if(t == currTime) {
                ++currTime;
                vvi newGrid(SZ(ss), vi(SZ(ss[0]), EMPTY));
                F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
                    if(grid[r][c] & WALL) newGrid[r][c] |= WALL;
                    if(grid[r][c] & U) newGrid[((r-1) - 1 + SZ(ss) - 2) % (SZ(ss) - 2) + 1][c] |= U;
                    if(grid[r][c] & D) newGrid[((r+1) - 1 + SZ(ss) - 2) % (SZ(ss) - 2) + 1][c] |= D;
                    if(grid[r][c] & L) newGrid[r][((c-1) - 1 + SZ(ss[0]) - 2) % (SZ(ss[0]) - 2) + 1] |= L;
                    if(grid[r][c] & R) newGrid[r][((c+1) - 1 + SZ(ss[0]) - 2) % (SZ(ss[0]) - 2) + 1] |= R;
                }
                grid = newGrid;
            }

            F0R(i, 5) {
                int rr = r + dr[i];
                int cc = c + dc[i];

                if(min(rr, cc) >= 0 && rr < SZ(ss) && cc < SZ(ss[0]) && grid[rr][cc] == EMPTY && !seen.count(mt(rr, cc, t + 1))) {
                    seen.emplace(rr, cc, t + 1);
                    q.emplace(rr, cc, t + 1);
                }
            }

        }
    }
    cout << currTime - 1 << endl;
}


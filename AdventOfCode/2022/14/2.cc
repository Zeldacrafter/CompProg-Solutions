#include "../utils.cc"

#define EMPTY 0
#define WALL 1
#define SAND 2
#define X_OFFSET 5000

void solve() {
    vvi grid(10000, vi(1000));
    ll maxY = 0;

    vector<string> ss = getInp([&](auto& cin, int) {
        ll lastX = -1, lastY = -1, x, y; char c; string s;
        do {
            if(lastX == -1 && lastY == -1) {
                cin >> lastX >> c >> lastY;
                lastX += X_OFFSET;
                ckmax(maxY, lastY);
            } else {
                cin >> s >> x >> c >> y;
                x += X_OFFSET;
                ckmax(maxY, y);

                FOR(i, min(x, lastX), max(x, lastX) + 1)
                    FOR(j, min(y, lastY), max(y, lastY) + 1)
                        grid[i][j] = WALL;

                lastX = x;
                lastY = y;
            }
        } while(cin.peek() == ' ');
    });
    F0R(i, SZ(grid)) grid[i][maxY + 2] = WALL;

    ll res = 0;
    while(grid[X_OFFSET + 500][0] == EMPTY) {
        for(int x = X_OFFSET + 500, y = 0;; ++y) {
            if(y == maxY) goto end;

            if(grid[x][y + 1] == EMPTY);
            else if (grid[x - 1][y + 1] == EMPTY)
                x--;
            else if (grid[x + 1][y + 1] == EMPTY)
                x++;
            else {
                grid[x][y] = SAND;
                res++;
                break;
            }
        }
    }
    cout << res << endl;
}


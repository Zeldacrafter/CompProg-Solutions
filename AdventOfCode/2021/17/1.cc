#include "../utils.cc"

void solve() {
    int minX, maxX, minY, maxY;
    getInp([&](auto& cin, int) {
        string s; char c;
        cin >> s >> s >> c >> c 
            >> minX >> c >> c >> maxX 
            >> c >> c >> c 
            >> minY >> c >> c >> maxY;
    });

    int res = 0;
    F0R(dx, maxX + 1) {
        FOR(dy, minY, 500) {
            int currDx = dx, currDy = dy, currX = 0, currY = 0;
            int highY = 0;
            while(currY >= minY) {
                currY += currDy--;
                currX += currDx;
                if(currDx > 0) currDx--;

                ckmax(highY, currY);

                if(minX <= currX && currX <= maxX && 
                   minY <= currY && currY <= maxY) {
                    ckmax(res, highY);
                    break;
                }
            }
        }
    }
    cout << res << endl;
}

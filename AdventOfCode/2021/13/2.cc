#include "../utils.cc"

void solve() {
    vector<ii> pts;
    getInp([&](auto& cin, int) {
        static bool part2 = false;
        if(!part2) {
            int x, y; char c;
            if(cin >> x >> c >> y) pts.eb(x, y);
            else part2 = true;
        } else {
            string s; char dir, c; int coord;
            cin >> s >> s >> dir >> c >> coord;

            F0R(i, SZ(pts)) {
                if(dir == 'x' && pts[i].fi > coord)
                    pts[i].fi = coord - (pts[i].fi - coord);
                else if(dir == 'y' && pts[i].se > coord)
                    pts[i].se = coord - (pts[i].se - coord);
            }
        }
    });

    map<ii, bool> isPt;
    int maxX = -1, maxY = -1;
    for(auto [x, y] : pts) {
        ckmax(maxX, x);
        ckmax(maxY, y);
        isPt[mp(x, y)] = true;
    }

    F0R(y, maxY + 1)  {
        F0R(x, maxX + 1) cout << (isPt[mp(x, y)] ? "⬜" : "⬛");
        cout << endl;
    }
}


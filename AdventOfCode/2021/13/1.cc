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

            sort(ALL(pts));
            cout << unique(ALL(pts)) - pts.begin() << endl;

            exit(0); // end programm after first fold
        }
    });
}


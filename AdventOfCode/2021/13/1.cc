#include "../utils.cc"

void solve() {
    set<ii> pts;
    getInp([&](auto& cin, int) {
        static bool part2 = false;
        if(!part2) {
            int x, y; char c;
            if(cin >> x >> c >> y) pts.emplace(x, y);
            else part2 = true;
        } else {
            string s; char dir, c; int coord;
            cin >> s >> s >> dir >> c >> coord;

            set<ii> newPts;
            for(auto [x, y] : pts) {
                if(dir == 'x' && x > coord)
                    newPts.emplace(coord - (x - coord), y);
                else if(dir == 'y' && y > coord)
                    newPts.emplace(x, coord - (y - coord));
                else
                    newPts.emplace(x, y);
            }
            cout << SZ(newPts) << endl;
            exit(0);
        }
    });
}


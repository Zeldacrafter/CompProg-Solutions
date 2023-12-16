#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    auto go = [&](ii startC, ii startDir) {
        queue<pair<ii, ii>> q;
        q.emplace(startC, startDir);

        set<pair<ii, ii>> seen { mp(startC, startDir) };
        set<ii> seenCoord { startC };

        auto ins = [&](ii coord, ii dir) {
            coord += dir;
            if(min(coord.fi, coord.se) < 0 || coord.fi >= SZ(ss) || coord.se >= SZ(ss[0])) return;
            if(seen.emplace(coord, dir).se) {
                q.emplace(coord, dir);
                seenCoord.insert(coord);
            }
        };
        
        while(SZ(q)) {
            auto [coord, dir] = q.front();
            auto [r, c] = coord;
            q.pop();

            if(ss[r][c] == '.' || (ss[r][c] == '-' && dir.se) || (ss[r][c] == '|' && dir.fi))
                ins(coord, dir);
            else if(ss[r][c] == '-')
                for(int i : {-1, 1}) ins(coord, mp(0, i));
            else if(ss[r][c] == '|')
                for(int i : {-1, 1}) ins(coord, mp(i, 0));
            else if(ss[r][c] == '/')
                ins(coord, mp(-dir.se, -dir.fi));
            else if(ss[r][c] == '\\')
                ins(coord, mp(dir.se, dir.fi));
            else 
                assert(false);
        }
        return SZ(seenCoord);
    };

    int res = 0;
    F0R(i, SZ(ss)) {
        ckmax(res, go(mp(i, 0), mp(0, 1)));
        ckmax(res, go(mp(i, SZ(ss[0])-1), mp(0, -1)));
    }
    F0R(i, SZ(ss[0])) {
        ckmax(res, go(mp(0, i), mp(1, 0)));
        ckmax(res, go(mp(SZ(ss)-1, i), mp(-1, 0)));
    }
    cout << res << endl;
}


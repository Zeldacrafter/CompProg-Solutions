#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    queue<pair<ii, ii>> q;
    q.emplace(mp(0, 0), mp(0, 1));

    set<pair<ii, ii>> seen { mp(mp(0, 0), mp(0, 1)) };
    set<ii> seenCoord { mp(0, 0) };

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

    cout << SZ(seenCoord) << endl;
}


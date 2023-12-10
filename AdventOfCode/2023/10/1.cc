#include "../utils.cc"

bool getDir(char c, ii& dir) {
    auto changeDir = [&](ii dir1, ii dir2) {
      if(dir == dir1) return dir = dir2, true;
      return false;
    };

    switch(c) {
        case 'S': return true;
        case '.': return false;
        case '|': return !dir.se;
        case '-': return !dir.fi;
        case 'L': return changeDir({ 1, 0}, {0,  1}) || changeDir({0, -1}, {-1, 0});
        case 'J': return changeDir({ 1, 0}, {0, -1}) || changeDir({0,  1}, {-1, 0});
        case '7': return changeDir({-1, 0}, {0, -1}) || changeDir({0,  1}, { 1, 0});
        case 'F': return changeDir({-1, 0}, {0,  1}) || changeDir({0, -1}, { 1, 0});
        default: assert(false);
    }
}

void solve() {
    vector<string> ss = getInp();

    ii start;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) if(ss[r][c] == 'S') start = mp(r, c);

    set<ii> loop;
    for(ii dir : vector<ii>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
        set<ii> seen;

        ii curr = start;
        seen.insert(start);
        while(true) {
            if(!getDir(ss[curr.fi][curr.se], dir)) break;

            curr += dir;
            if(!seen.insert(curr).se) {
                if(curr == start) loop = seen;
                break;
            }
        }
        if(SZ(loop)) break;
    }
    cout << SZ(loop)/2 << endl;
}

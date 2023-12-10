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

    // Dont wannt do this in general :(
    ss[start.fi][start.se] = 'J';

    int res = 0;
    F0R(r, SZ(ss)) {
      bool in = false;
      for(int c = 0; c < SZ(ss[r]); ++c) {
          if(loop.count({r, c})) {
              if(ss[r][c] == '|') in ^= 1;
              else if(ss[r][c] == 'F' || ss[r][c] == 'L') {
                  char ch = ss[r][c];
                  while(ss[r][++c] == '-');
                  in ^= (ch == 'F' && ss[r][c] == 'J') || (ch == 'L' && ss[r][c] == '7');
              }          
          } else {
              res += in;
          }
      }
    }
    cout << res << endl;
}

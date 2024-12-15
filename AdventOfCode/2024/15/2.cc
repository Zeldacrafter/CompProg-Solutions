#include "../utils.cc"
// character, (if O:) if it the left
vector<string> grid;

char get(ii pos) { return grid[pos.fi][pos.se]; }
void modify(ii pos, char c) { grid[pos.fi][pos.se] = c; }

bool canMove(ii pos, ii dir) {
    if(get(pos + dir)== '#') return false;
    if(get(pos + dir)== '.') return true;
    if(get(pos + dir) == '@') return canMove(pos + dir, dir);
    if(get(pos + dir) == '[' || get(pos + dir) == ']') {
        return canMove(pos + dir, dir) && 
            (dir.se || 
             canMove(pos + dir + mp(0, get(pos + dir) == '[' ? 1 : -1), dir));
    }
    assert(false);
}

void doMove(ii pos, ii dir) {
    if(get(pos) == '.') return;
    if(get(pos + dir) == '#') return;

    if(get(pos + dir) != '.') doMove(pos + dir, dir); 
    modify(pos + dir, get(pos));
    modify(pos, '.');
    
    if(!dir.se && (get(pos + dir) == ']' || get(pos + dir) == '[')) {
        ii delta = mp(0, get(pos + dir) == '[' ? 1 : -1);
        doMove(pos + dir + delta, dir);
        modify(pos + dir + delta, get(pos + delta));
        modify(pos + delta, '.');
    }
}

void solve() {
    vector<string> ss = getInp();

    string seq = "";
    bool isGrid = true;
    for(string& s : ss) {
        if(s == "") {
            isGrid = false;
        } else {
            if(isGrid) {
                grid.eb();
                for(char c : s) {
                    if(c == '.' || c == '#') {
                        grid.back().pb(c);
                        grid.back().pb(c);
                    } else if(c == '@') {
                        grid.back().pb('@');
                        grid.back().pb('.');
                    } else if(c == 'O') {
                        grid.back().pb('[');
                        grid.back().pb(']');
                    }
                }
            } else { 
                seq += s;
            }
        }
    }

    map<char, ii> dirs;
    dirs['^'] = mp(-1, 0);
    dirs['v'] = mp(1, 0);
    dirs['>'] = mp(0, 1);
    dirs['<'] = mp(0, -1);

    ii pos;
    F0R(i, SZ(grid)) F0R(j, SZ(grid[i]))
        if(grid[i][j] == '@') pos = mp(i, j);

    for(char c : seq) {
        if(canMove(pos, dirs[c])) { 
            doMove(pos, dirs[c]);
            pos += dirs[c]; 
        }
    }

    ll res = 0;
    F0R(r, SZ(grid)) F0R(c, SZ(grid[0]))
        if(grid[r][c] == '[') res += r*100 + c;
    cout << res << endl;

}

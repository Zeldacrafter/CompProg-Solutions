#include "../utils.cc"
map<char, ii> dirs{{'<', {0, -1}}, {'^', {-1, 0}}, {'>', {0, 1}}, {'v', {1, 0}}};
vector<string> grid;

char& get(ii pos) { return grid[pos.fi][pos.se]; }

bool move(ii pos, ii dir) {
    if(get(pos + dir) == '#') return false;

    bool ok = get(pos + dir) == '.' || move(pos + dir, dir);
    if(ok) { 
        get(pos + dir) = get(pos);
        get(pos) = '.';
    }
    return ok;
}

void solve() {
    vector<string> ss = getInp();

    string seq = "";
    bool isGrid = true;
    for(string& s : ss) {
        if(s == "") {
            isGrid = false;
        } else {
            if(isGrid) grid.pb(s);
            else seq += s;
        }
    }

    ii pos;
    F0R(i, SZ(grid)) F0R(j, SZ(grid[i]))
        if(grid[i][j] == '@') pos = mp(i, j);

    for(char c : seq) {
        if(move(pos, dirs[c])) {
            pos += dirs[c]; 
        }
    }

    ll res = 0;
    F0R(r, SZ(grid)) F0R(c, SZ(grid[0]))
        if(grid[r][c] == 'O') res += r*100 + c;
    cout << res << endl;
}


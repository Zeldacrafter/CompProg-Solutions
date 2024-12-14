#include "../utils.cc"

const pair<ll, ll> grid = {101, 103};
//const pair<ll, ll> grid = {11, 7};

void solve() {
    vector<pair<ll, ll>> pos, vel;
    getInp([&](auto& cin, int) {
        pos.eb(); vel.eb();
        cin >> pos.back() >> vel.back();
    }, "p=(-?[0-9]*),(-?[0-9]*) v=(-?[0-9]*),(-?[0-9]*)");

    for(int t = 0; ; ++t) {
        vector<string> seen(grid.se, string(grid.fi, '.'));
        bool ok = true;
        F0R(i, SZ(pos)) {
            auto [x, y] = ((pos[i] + t*vel[i]) % grid + grid) % grid;
            if(seen[y][x] == '#') { 
                ok = false;
                break; 
            }
            seen[y][x] = '#';
        }
        if(ok) {
            cout << "Printing at t=" << t << ":" << endl
                 << pp(seen, "\n") << endl << endl;
        }
    }

}


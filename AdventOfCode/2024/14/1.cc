#include "../utils.cc"

const pair<ll, ll> grid = {101, 103};
//const pair<ll, ll> grid = {11, 7};

void solve() {
    vector<pair<ll, ll>> pos, vel;
    getInp([&](auto& cin, int) {
        pos.eb(); vel.eb();
        cin >> pos.back() >> vel.back();
    }, "p=(-?[0-9]*),(-?[0-9]*) v=(-?[0-9]*),(-?[0-9]*)");

    array<ll, 4> qs = {};
    F0R(i, SZ(pos)) {
        pair<ll, ll> pp = ((pos[i] + 100*vel[i]) % grid + grid) % grid;

        if(pp.fi == grid.fi/2 || pp.se == grid.se/2) continue;
        bool left = pp.fi < grid.fi/2, up = pp.se < grid.se/2;
        qs[(left << 1) | up]++;
    }

    cout << qs[0]*qs[1]*qs[2]*qs[3] << endl;
}


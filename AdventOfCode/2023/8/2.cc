#include "../utils.cc"

void solve() {
    map<string, pair<string, string>> adj;
    string dirs;

    vector<string> ss = getInp([&](auto& cin, int i) {
        if(!i) cin >> dirs;
        else { 
            string s, l, r; char c;
            if(cin >> s >> c >> c >> l >> r) {
                l.pop_back();
                r.pop_back();
                adj[s] = mp(l, r);
            }
        }
    });

    vector<string> pos;
    for(auto [s, p] : adj) if(s.back() == 'A') pos.pb(s);

    map<int, ll> times;
    for(ll steps = 0; SZ(times) != SZ(pos); ++steps) {
        F0R(i, SZ(pos)) {
            pos[i] = dirs[steps % SZ(dirs)] == 'L' ? adj[pos[i]].fi : adj[pos[i]].se;
            if(pos[i].back() == 'Z') times[i] = steps + 1;
        }
    }

    // Assumes that input is nice:
    //   After xxZ we always return to the thing we visited after xxA.
    //   Only one endPoint is reachable from each start-point
    //   => We simply have to solve `steps % times[i] = 0` for all i.
    // In general we would need to solve `steps % times[i] = x[i]` for all i and some x[i], 
    //   which needs chinese remainder theorem.
    ll res = times[0];
    F0R(i, SZ(times)) res = lcm(res, times[i]);
    cout << res << endl;
}


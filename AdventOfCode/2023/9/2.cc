#include "../utils.cc"

void solve() {
    vector<vector<ll>> inp;
    getInp([&](auto& cin, int) {
        inp.eb();
        for(ll k; cin >> k; inp.back().pb(k));
    });

    ll res = 0;
    for(vector<ll>& hist : inp) {
        vector<vector<ll>> layer = {hist};
        while(!all_of(ALL(layer.back()), [](ll x) { return !x; })) {
            vector<ll> last = layer.back();
            layer.eb();
            F0R(i, SZ(last) - 1) layer.back().pb(last[i+1] - last[i]);
        }
        for(int i = SZ(layer) - 2; ~i; --i)
            layer[i].insert(layer[i].begin(), layer[i][0] - layer[i+1][0]);        
        res += layer[0][0];
    }
    cout << res << endl;
}

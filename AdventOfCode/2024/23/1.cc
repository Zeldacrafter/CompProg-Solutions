#include "../utils.cc"

void solve() {
    set<string> inp;
    map<string, set<string>> adj;

    getInp([&](auto& cin, int) {
        string s; cin >> s;
        auto [a, b] = splitP(s, "-");
        adj[a].insert(b);
        adj[b].insert(a);
        inp.insert(a);
        inp.insert(b);
    });

    ll res = 0;
    for(auto& x1 : inp) for(auto& x2 : inp) for(auto& x3 : inp) {
        res += (x1[0] == 't' || x2[0] == 't' || x3[0] == 't')
            && x1 < adj[x2]
            && x1 < adj[x3]
            && x2 < adj[x3];
    }
    cout << res/6 << endl;
}


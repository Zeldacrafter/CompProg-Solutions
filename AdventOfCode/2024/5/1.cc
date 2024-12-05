#include "../utils.cc"

void solve() {
    map<int, set<int>> adj;
    vvi updates;
    getInp([&](auto& cin, int) {
        ll k; char c; cin >> k >> c;
        if(c == '|') {
            ll k2; cin >> k2;
            adj[k2].insert(k);
        } else {
            updates.eb();
            updates.back().pb(k);
            do {
                cin >> k;
                updates.back().pb(k);
            } while(cin >> c);
        }
    });

    ll res = 0;
    for(vi& update : updates) {
        bool ok = true;
        F0R(i, SZ(update)) F0R(j, i)
            ok &= !adj[update[j]].contains(update[i]);
        if(!ok) continue;

        res += update[SZ(update)/2];
    }
    cout << res << endl;
}


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
        if(ok) continue;

        map<int, int> in;
        for(int v : update)
            for(int u : adj[v])
                in[u] += !!count(ALL(update), v);

        vi q;
        for(int v : update) if(!in[v]) q.pb(v);
        assert(SZ(q));
        F0R(i, SZ(q))
            for (int v : adj[q[i]])
                if(count(ALL(update), v) && !--in[v]) 
                    q.pb(v);
        assert(SZ(q) == SZ(update));

        res += q[SZ(q)/2];
    }
    cout << res << endl;
}


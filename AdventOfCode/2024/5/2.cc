#include "../utils.cc"

map<int, vi> adj;
set<int> reaches(int v, vi& update) {
    set<int> res = {v};
    queue<int> q;
    q.push(v);

    while(SZ(q)) {
        int curr = q.front(); q.pop();
        for(int u : adj[curr]) {
            if(res.count(u) || !count(ALL(update), u)) continue;
            q.push(u);
            res.insert(u);
        }
    }
    return res;
}

void solve() {
    vvi updates;
    getInp([&](auto& cin, int) {
        ll k; char c; cin >> k >> c;
        if(c == '|') {
            ll k2; cin >> k2;
            adj[k].pb(k2);
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
        F0R(i, SZ(update)) {
            set<int> reach = reaches(update[i], update);
            F0R(j, i) ok &= !reach.count(update[j]);
            if(!ok) break;
        }
        if(ok) continue;

        map<int, int> in;
        for(int v : update)
            for(int u : adj[v])
                in[u] += !!count(ALL(update), u);

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


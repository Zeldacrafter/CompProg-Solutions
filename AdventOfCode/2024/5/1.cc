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
        if(!ok) continue;

        res += update[SZ(update)/2];
    }
    cout << res << endl;
}


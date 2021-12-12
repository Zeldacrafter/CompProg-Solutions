#include "../utils.cc"

void solve() {
    map<string, int> toInt;
    vector<bool> isSmall;
    vvi adj;
    getInp([&](auto& cin, int) {
        string line; cin >> line;
        string pt1 = line.substr(0, line.find("-")), pt2 = line.substr(SZ(pt1) + 1);

        for(string s : {pt1, pt2}) if(!toInt.count(s)) {
            toInt[s] = SZ(adj);
            isSmall.pb(islower(s[0]));
            adj.eb();
        }
        adj[toInt[pt1]].pb(toInt[pt2]);
        adj[toInt[pt2]].pb(toInt[pt1]);
    });

    vi seen(SZ(adj));
    auto dfs = y_combinator([&](auto self, int v, int twiceNode = -1) -> ll {
        if(v == toInt["end"]) return twiceNode == -1 || seen[twiceNode] == 2;

        if(isSmall[v]) seen[v]++;
        ll res = 0;
        for(int u : adj[v])
            if(seen[u] < 1 + (u == twiceNode))
                res += self(u, twiceNode);
        if(isSmall[v]) seen[v]--;
        return res;
    });

    ll res = dfs(toInt["start"]);
    F0R(i, SZ(adj)) if(i != toInt["start"] && isSmall[i]) {
        fill(ALL(seen), 0);
        res += dfs(toInt["start"], i);
    }
    cout << res << endl;
}


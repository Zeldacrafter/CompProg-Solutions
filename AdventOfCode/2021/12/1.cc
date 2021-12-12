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

    vector<bool> seen(SZ(adj));
    auto dfs = y_combinator([&](auto self, int v) -> ll {
        if(v == toInt["end"]) return 1;

        if(isSmall[v]) seen[v] = true;
        ll res = 0;
        for(int u : adj[v])
            if(!seen[u])
                res += self(u);
        if(isSmall[v]) seen[v] = false;
        return res;
    });

    cout << dfs(toInt["start"]) << endl;
}


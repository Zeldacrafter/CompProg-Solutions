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

    ll res = 0;
    for(string curr = "AAA"; curr != "ZZZ"; ++res)
        curr = dirs[res % SZ(dirs)] == 'L' ? adj[curr].fi : adj[curr].se;
    cout << res << endl;
}


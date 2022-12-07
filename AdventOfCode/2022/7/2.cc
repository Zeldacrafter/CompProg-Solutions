#include "../utils.cc"

void solve() {
    vector<string> curr;
    string currDir;
    map<string, ll> size;
    map<string, bool> done;
    bool first = true;

    getInp([&](auto& cin, int) {
        if(cin.peek() == '$') {
            char c; string comm; cin >> c >> comm;

            if(comm == "cd") {
                string s; cin >> s;

                if(!first) done[currDir] = true;

                if(s == "/") {
                    curr.clear();
                    currDir = "";
                } else if(s == "..") {
                    currDir = currDir.substr(0, SZ(currDir) - SZ(curr.back()) - 1);
                    curr.pop_back();
                } else {
                    curr.pb(s);
                    currDir += "/" + s;
                }
                first = false;
            } 
        } else {
            if(cin.peek() != 'd' && !done[currDir]) {
                ll sz; cin >> sz;

                string dir = "";
                size[dir] += sz;
                for(string& d : curr) {
                    dir += "/" + d;
                    size[dir] += sz;
                }
            }
        }
    });

    ll goal = 70000000 - 30000000, currBest = -1;
    for(auto [k, v] : size)
        if(size[""] - v <= goal && (currBest == -1 || v < currBest))
            currBest = v;
    cout << currBest << endl;
}


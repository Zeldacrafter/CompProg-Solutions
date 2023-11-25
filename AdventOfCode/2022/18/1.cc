#include "../utils.cc"

set<tuple<int, int, int>> coords;



void solve() {
    ll res = 0;
    vector<ll> inp;
    vector<string> ss = getInp([&](auto& cin, int i) {
        int x, y, z; char c;
        cin >> x >> c >> y >> c >> z;
        coords.emplace(x, y, z);
    });

    for(auto [x, y, z] : coords)
        FOR(i, -1, 2) FOR(j, -1, 2) FOR(k, -1, 2) 
            if(abs(i) + abs(j) + abs(k) == 1)
                res += !coords.count(mt(x+i, y+j, z+k));

    /*
    ss.pb("");
    for(string& s : ss) {
        if(s == "") {

        } else {

        }
    }
    */

    cout << res << endl;
}


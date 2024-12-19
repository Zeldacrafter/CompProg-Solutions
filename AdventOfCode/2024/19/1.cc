#include "../utils.cc"

vector<string> poss;
ll ways(string s) {
    static map<string, ll> dp;
    if(!SZ(s)) return 1;
    if(dp.count(s)) return dp[s];

    ll res = 0;
    for(string& p : poss) {
        if(SZ(p) <= SZ(s) && equal(ALL(p), s.begin()))
            res += ways(s.substr(SZ(p)));
    }
    return dp[s] = res;
}

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
            string s;
            if(!(cin >> s)) return;
            if(s.back() == ',') {
                do {
                    if(s.back() == ',') s.pop_back();
                    poss.pb(s);
                } while(cin >> s);
            } else {
                res += !!ways(s);
            }
    });
    cout << res << endl;
}


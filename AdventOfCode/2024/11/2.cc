#include "../utils.cc"

map<pair<ll, int>, ll> dp;

ll calc(ll x, int amt) {
    if(dp.count({x, amt})) return dp[{x, amt}];

    if(!amt) return 1;
    if(!x) return dp[{x, amt}] = calc(1, amt - 1);

    string st = to_string(x);
    if(SZ(st) % 2 == 0) 
        return dp[{x, amt}] = calc(stoll(st.substr(0, SZ(st)/2)), amt - 1 ) 
                            + calc(stoll(st.substr(SZ(st)/2)), amt - 1);

    return dp[{x, amt}] = calc(x * 2024, amt - 1);
}

void solve() {
    vector<string> ss = split(getInp()[0], " ");

    ll res = 0;
    for(string& s : ss) res += calc(stoll(s), 75);
    cout << res << endl;
}


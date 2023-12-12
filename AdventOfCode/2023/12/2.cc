#include "../utils.cc"

ll getAmt(const string& s, const vi& amts, int s_i = 0, int amts_i = 0, int cnt = 0) {
    static map<tuple<int, int, int>, ll> dp;
    if(!s_i) dp.clear();

    tuple<int, int, int> curr(s_i, amts_i, cnt);
    if(dp.count(curr)) return dp[curr];

    if(s_i == SZ(s))
        return (amts_i == SZ(amts) && !cnt) || (amts_i == SZ(amts) - 1 && amts.back() == cnt);

    ll res = 0;
    for(char c : ".#") {
        if(s[s_i] == c || s[s_i] == '?') {
            if(c == '.' && !cnt) 
                res += getAmt(s, amts, s_i + 1, amts_i, 0);
            else if(c == '.' && cnt && amts_i < SZ(amts) && amts[amts_i] == cnt)
                res += getAmt(s, amts, s_i + 1, amts_i + 1, 0);
            else if(c == '#')
                res += getAmt(s, amts, s_i + 1, amts_i, cnt + 1);
        }
    }
    return dp[curr] = res;
}

void solve() {
    vector<string> ss;
    vvi xs;

    getInp([&](auto& cin, int) {
        string s; char c; int n; cin >> s >> n;
        ss.pb(s + "?" + s + "?" + s + "?" + s + "?" + s);

        vi ns {n};
        while(cin >> c >> n) ns.pb(n);
        xs.eb();
        F0R(i, 5) xs.back().insert(xs.back().end(), ALL(ns));
    });

    ll res = 0;
    F0R(i, SZ(ss)) res += getAmt(ss[i], xs[i]);
    cout << res << endl;
}


#include "../utils.cc"

int getType(string s) {
    sort(ALL(s));

    if(s[0] == s[4])
        return 0;
    if(s[0] == s[3] || s[1] == s[4])
        return 1;
    if((s[0] == s[1] && s[1] != s[2] && s[2] == s[4]) ||
       (s[0] == s[2] && s[2] != s[3] && s[3] == s[4]))
        return 2;
    if(s[0] == s[2] || s[1] == s[3] || s[2] == s[4])
        return 3;
    if((s[0] == s[1] && s[2] == s[3]) || 
       (s[0] == s[1] && s[3] == s[4]) || 
       (s[1] == s[2] && s[3] == s[4]))
        return 4;
    if(s[0] == s[1] || s[1] == s[2] || s[2] == s[3] || s[3] == s[4])
        return 5;
    return 6;
}

void solve() {
    map<char, int> val;
    FOR(i, '2', '9' + 1) val[i] = i - '2';
    val['T'] = 8;
    val['J'] = -1;
    val['Q'] = 10;
    val['K'] = 11;
    val['A'] = 12;

    map<int, vector<pair<string, ll>>> toType;

    getInp([&](auto& cin, int) {
        string s; ll bid; cin >> s >> bid;
        int type = 7;
        for(char c : "23456789TQKA") {
            string s2 = s;
            F0R(i, 5) if(s2[i] == 'J') s2[i] = c;
            ckmin(type, getType(s2));
        }
        toType[type].eb(s, bid);
    });

    ll cnt = 0;
    F0R(i, 7) {
        cnt += SZ(toType[i]);
        sort(ALL(toType[i]), [&](auto& s1, auto& s2) {
            F0R(i, 5)
                if(s1.fi[i] != s2.fi[i])
                    return val[s1.fi[i]] > val[s2.fi[i]];
            assert(false); // Same card set
            return false;
        });
    }

    ll res = 0;
    F0R(i, 7)
        for(auto& [h, bid] : toType[i])
            res += bid * cnt--;
    cout << res << endl;
}

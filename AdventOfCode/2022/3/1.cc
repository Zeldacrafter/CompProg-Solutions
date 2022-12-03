#include "../utils.cc"

void solve() {
    ll res = 0;
    vector<string> ss = getInp([&](auto& cin, int) {
        string s; cin >> s;
        
        char c = *(set(SZ(s)/2 + ALL(s)) & 
                   set(ALL(s) - SZ(s)/2)).begin();
        if(c >= 'a' && c <= 'z')
            res += c - 'a' + 1;
        else
            res += c - 'A' + 27;
    });
    cout << res << endl;
}


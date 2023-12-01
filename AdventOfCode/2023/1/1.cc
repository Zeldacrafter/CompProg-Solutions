#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    ll res = 0;
    for(string& s : ss) {
        vi v;
        for(char c : s) if(isdigit(c)) v.pb(c - '0');
        res += v.front()*10 + v.back();
    }
    cout << res << endl;
}


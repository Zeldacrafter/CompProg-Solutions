#include "../template.cc"

void solve() {
    ll res = 0;
    vector<string> ss = getInp();
    ss.pb("");

    set<char> valid;
    for(string& s : ss) {
        if(s == "") {
            res += SZ(valid);
            valid.clear();
        } else {
            for(char c : s)
                valid.insert(c);
        } 
    }

    cout << res << endl;
}

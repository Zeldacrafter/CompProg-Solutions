#include "../template.cc"

void solve() {
    ll res = 0;
    vector<string> ss = getInp();
    ss.pb("");

    set<char> valid;
    F0R(i, 26) valid.insert('a' + i);
    for(string& s : ss) {
        if(s == "") {
            res += SZ(valid);
            F0R(i, 26) valid.insert('a' + i);
        } else {
            set<char> v2;
            for(char c : s)
                if(valid.count(c))
                    v2.insert(c);

            valid = v2;
        } 
    }

    cout << res << endl;
}



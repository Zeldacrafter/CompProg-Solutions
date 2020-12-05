#include "../template.cc"

void solve() {
    ll res = 0;

    vector<string> ss = getInp();
    for(string& s : ss) {
        ll id = 0;
        for(char c : s) {
            id *= 2;
            if(c == 'B' || c == 'R')
                id++;
        }
        ckmax(res, id);
    }

    cout << res << endl;
}


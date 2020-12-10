#include "../template.cc"

void solve() {
    vector<string> ss = getInp();

    vector<bool> v(1 << 10);
    for(string& s : ss) {
        ll id = 0;
        for(char c : s) {
            id *= 2;
            if(c == 'B' || c == 'R')
                id++;
        }
        v[id] = true;
    }

    FOR(i, 1, SZ(v) - 1)
        if(v[i - 1] && !v[i] && v[i + 1])
            cout << i << endl;
}


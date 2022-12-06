#include "../utils.cc"

#define LEN 14

void solve() {
    string s = getInp()[0];

    F0R(i, SZ(s) - LEN) {
        set<char> cs(s.begin() + i, s.begin() + i + LEN);
        if(SZ(cs) == LEN) {
            cout << i + LEN << endl;
            return;
        }
    }
}


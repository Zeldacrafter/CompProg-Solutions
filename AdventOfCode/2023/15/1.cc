#include "../utils.cc"

int getHash(string s) {
    int val = 0;
    for(char c : s) val = (val + c) * 17 % 256;
    return val;
}

void solve() {
    vector<string> ss = split(getInp()[0], ",");

    ll res = 0;
    for(string& s : ss) res += getHash(s);
    cout << res << endl;
}

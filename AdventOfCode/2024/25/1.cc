#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    vector<vector<ll>> lock, key;
    bool start = true, isKey = true;
    ss.pb("");
    for(string& s : ss) {
        if(s == "") {
            start = true;
            if(!isKey) {
                F0R(i, 5) lock.back()[i] = 6 - lock.back()[i];
            } else if(SZ(key)) {
                F0R(i, 5) key.back()[i] = 6 - key.back()[i] - 1;
            }
        } else {
            if(start) {
                isKey = s[0] == '.';
                (isKey ? key : lock).pb(vector<ll>(5, 0));
            } else {
                F0R(i, 5) (isKey ? key : lock).back()[i] += s[i] == '.';
            }
            start = false;
        }
    }

    ll res = 0;
    F0R(i, SZ(lock)) F0R(j, SZ(key)) {
        bool ok = true;
        F0R(k, 5) ok &= lock[i][k] + key[j][k] < 6;
        res += ok;
    }
    cout << res << endl;
}


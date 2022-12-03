#include "../utils.cc"

void solve() {
    ll res = 0;
    vector<string> ss = getInp();

    F0R(_i, SZ(ss)/3) {
        int i = 3*_i;

        char c = *(set(ALL(ss[i])) & 
                   set(ALL(ss[i + 1])) & 
                   set(ALL(ss[i + 2]))).begin();
        if(c >= 'a' && c <= 'z')
            res += c - 'a' + 1;
        else
            res += c - 'A' + 27;
    }

    cout << res << endl;
}


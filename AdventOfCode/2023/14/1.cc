#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    vi top(SZ(ss[0]), -1);
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        if(ss[r][c] == '#') top[c] = r;
        else if(ss[r][c] == 'O') {
            ss[r][c] = '.';
            ss[++top[c]][c] = 'O';
        }
    }

    ll res = 0;
    F0R(r, SZ(ss))
        F0R(c, SZ(ss[r]))
            if(ss[r][c] == 'O')
                res += SZ(ss) - r;

    cout << res << endl;
}


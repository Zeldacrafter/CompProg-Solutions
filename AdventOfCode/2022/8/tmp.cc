#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    vector<vector<bool>> v(SZ(ss[0]), vector<bool>(SZ(ss)));

    F0R(r, SZ(ss)) {
        char mx = -1;
        F0R(c, SZ(ss[0]))
            if(ckmax(mx, ss[r][c]))
                v[r][c] = true;
        mx = -1;
        for(int c = SZ(ss[0]) - 1; ~c; --c)
            if(ckmax(mx, ss[r][c]))
                v[r][c] = true;
    }
    F0R(c, SZ(ss[0])) {
        char mx = -1;
        F0R(r, SZ(ss))
            if(ckmax(mx, ss[r][c]))
                v[r][c] = true;
        mx = -1;
        for(int r = SZ(ss) - 1; ~r; --r)
            if(ckmax(mx, ss[r][c]))
                v[r][c] = true;
    }

    ll res = 0;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) res += v[r][c];
    cout << res << endl;
}


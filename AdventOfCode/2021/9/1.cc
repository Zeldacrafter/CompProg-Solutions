#include "../utils.cc"

void solve() {
    vector<string> s = getInp();

    ll res = 0;
    F0R(r, SZ(s)) F0R(c, SZ(s[r])) {
        bool ok = true;
        F0R(i, 4) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(min(rr, cc) < 0 || rr >= SZ(s) || cc >= SZ(s[r])) continue;
            ok &= s[r][c] < s[rr][cc];
        }
        if(ok) res += s[r][c] - '0' + 1;

    }
    cout << res << endl;
}


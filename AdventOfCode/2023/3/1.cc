#include "../utils.cc"


void solve() {
    vector<string> ss = getInp();

    set<ii> coords;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        if(ss[r][c] != '.' && !isdigit(ss[r][c])) {
            FOR(dr, -1, 2) FOR(dc, -1, 2) {
                int rr = r + dr, cc = c + dc;
                if(isdigit(ss[rr][cc])) {
                    while(cc > 0 && isdigit(ss[rr][cc-1])) --cc;
                    coords.emplace(rr, cc);
                }
            }
        }
    }

    ll res = 0;
    for(auto [r, c] : coords) {
        int num = 0;
        for(; c < SZ(ss[0]) && isdigit(ss[r][c]); num = num*10 + ss[r][c++] - '0');
        res += num;
    }
    cout << res << endl;
}


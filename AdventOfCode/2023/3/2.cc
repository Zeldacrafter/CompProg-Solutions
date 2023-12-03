#include "../utils.cc"


void solve() {
    vector<string> ss = getInp();

    set<pair<ii, ii>> coords;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        if(ss[r][c] == '*') {
            set<ii> curr;
            FOR(dr, -1, 2) FOR(dc, -1, 2) {
                int rr = r + dr, cc = c + dc;
                if(isdigit(ss[rr][cc])) {
                    while(cc > 0 && isdigit(ss[rr][cc-1])) --cc;
                    curr.emplace(rr, cc);
                }
            }
            if(SZ(curr) == 2) coords.emplace(*curr.begin(), *next(curr.begin()));
        }
    }

    ll res = 0;
    for(auto [p1, p2] : coords) {
        int num1 = 0, num2 = 0;
        for(auto [r1, c1] = p1; c1 < SZ(ss[0]) && isdigit(ss[r1][c1]); num1 = num1*10 + ss[r1][c1++] - '0');
        for(auto [r2, c2] = p2; c2 < SZ(ss[0]) && isdigit(ss[r2][c2]); num2 = num2*10 + ss[r2][c2++] - '0');
        res += num1*num2;
    }

    cout << res << endl;
}


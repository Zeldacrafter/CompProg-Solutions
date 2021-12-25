#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    auto move = [&](char ch, int dr, int dc) {
        bool change = false;
        vector<string> newSs(SZ(ss), string(SZ(ss[0]), '?'));
        F0R(r, SZ(ss)) F0R(c, SZ(ss[r])) {
            if(ss[r][c] == ch && ss[(r + dr) % SZ(ss)][(c + dc) % SZ(ss[r])] == '.') {
                newSs[r][c] = '.';
                newSs[(r + dr) % SZ(ss)][(c + dc) % SZ(ss[r])] = ch;
                change = true;
            }
        }
        F0R(r, SZ(ss)) F0R(c, SZ(ss[r]))
            if(newSs[r][c] == '?') newSs[r][c] = ss[r][c];
        ss = newSs;
        return change;
    };

    ll res = 0;
    for(bool change = true; !(change ^= 1); ++res) {
        change |= move('>', 0, 1);
        change |= move('v', 1, 0);
    }

    cout << res << endl;
}


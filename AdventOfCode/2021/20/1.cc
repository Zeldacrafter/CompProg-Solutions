#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    string alg = ss[0];
    ss.erase(ss.begin(), ss.begin() + 2);

    F0R(iter, 2) {
        vector<string> ssNew(SZ(ss) + 4, string(SZ(ss[0]) + 4, '_'));
        F0R(r, SZ(ssNew)) F0R(c, SZ(ssNew)) {
            int val = 0;
            FOR(dr, -1, 2) FOR(dc, -1, 2) {
                int rr = r + dr - 2, cc = c + dc - 2;

                char ch;
                if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[rr]))
                    ch = iter & 1 ? alg[0] : '.';
                else
                    ch = ss[rr][cc];

                val = val*2 + (ch == '#');
            }
            ssNew[r][c] = alg[val];
        }
        swap(ss, ssNew);
    }

    ll res = 0;
    F0R(r, SZ(ss)) F0R(c, SZ(ss))  res += ss[r][c] == '#';
    cout << res << endl;
}


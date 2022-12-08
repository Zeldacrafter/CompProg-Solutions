#include "../utils.cc"

const vi DR = {-1, 1, 0, 0}, DC = {0, 0, 1, -1};

void solve() {
    vector<string> ss = getInp();

    ll res = 0;

    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        ll total = 1;
        F0R(i, 4) {
            int amt = 0;
            int dr = DR[i], dc = DC[i];
            for(int rr = r + dr, cc = c + dc;
                  ~min(rr, cc) && rr < SZ(ss) && cc < SZ(ss[0]) ; 
                  rr += dr, cc += dc) {
                amt++;
                if(ss[rr][cc] >= ss[r][c]) break;
            }
            total *= amt;
        }
        ckmax(res, total);
    }

    cout << res << endl;
}


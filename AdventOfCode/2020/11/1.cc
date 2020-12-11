#include "../template.cc"

const int CHANGE_AMT = 4;

void solve() {
    vector<string> ss = getInp();

    int h = SZ(ss[0]);
    int w = SZ(ss);

    while(true) {
        vvi cnts(w, vi(h));
        F0R(c, w) F0R(r, h) {
            FOR(dc, -1, 2) FOR(dr, -1, 2) {
                if(!dc && !dr) continue;
                int cc = c + dc, rr = r + dr;
                cnts[c][r] += min(rr, cc) >= 0 && rr < h && cc < w && ss[cc][rr] == '#';
            }
        }

        bool change = false;
        F0R(c, w) F0R(r, h) {
            if(ss[c][r] == 'L' && !cnts[c][r]) {
                ss[c][r] = '#';
                change = true;
            } else if(ss[c][r] == '#' && cnts[c][r] >= CHANGE_AMT) {
                ss[c][r] = 'L';
                change = true;
            }            
        }
        if(!change)
            break;
    }

    ll res = 0;
    F0R(c, w) F0R(r, h)
        res += ss[c][r] == '#';
    cout << res << endl;
}

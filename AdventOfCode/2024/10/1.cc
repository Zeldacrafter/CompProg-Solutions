#include "../utils.cc"

vii d = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<string> ss;

bool in(ii pos) {
    return min(pos.fi, pos.se) >= 0 && pos.fi < SZ(ss) && pos.se < SZ(ss[0]);
}

set<ii> getAmt(ii pos) {
    if(ss[pos.fi][pos.se] == '9') return set<ii>({pos});

    set<ii> ret;
    F0R(i, 4) {
        ii newPos = pos + d[i];
        if(in(newPos) && ss[newPos.fi][newPos.se] == ss[pos.fi][pos.se] + 1)
            ret |= getAmt(newPos);
    }
    return ret;
}



void solve() {
    ss = getInp();

    ll res = 0;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0]))
        if(ss[i][j] == '0')
            res += SZ(getAmt(mp(i, j)));
    cout << res << endl;
}


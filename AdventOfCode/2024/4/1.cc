#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    auto is = [&](int i, int j, int di, int dj) {
        return i + 3*di >= 0 && i + 3*di < SZ(ss)
            && j + 3*dj >= 0 && j + 3*dj < SZ(ss[0])
            && ss[i       ][j       ] == 'X' 
            && ss[i +   di][j +   dj] == 'M'
            && ss[i + 2*di][j + 2*dj] == 'A'
            && ss[i + 3*di][j + 3*dj] == 'S';
    };

    ll res = 0;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0]))
        FOR(di, -1, 2) FOR(dj, -1, 2)
            res += is(i, j, di, dj);
    cout << res << endl;
}


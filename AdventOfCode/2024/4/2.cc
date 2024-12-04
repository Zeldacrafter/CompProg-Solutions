#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    auto is = [&](int i, int j, int di, int dj) {
        return i + 2*di >= 0 && i + 2*di < SZ(ss)
            && j + 2*dj >= 0 && j + 2*dj < SZ(ss[0])
            && i < SZ(ss) && j < SZ(ss[0])
            && ss[i       ][j       ] == 'M' 
            && ss[i +   di][j +   dj] == 'A'
            && ss[i + 2*di][j + 2*dj] == 'S';
    };

    ll res = 0;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0])) {
        res += is(i    , j    ,  1,  1) && is(i    , j + 2,  1, -1);
        res += is(i    , j    ,  1,  1) && is(i + 2, j    , -1,  1);
        res += is(i + 2, j + 2, -1, -1) && is(i    , j + 2,  1, -1);
        res += is(i + 2, j + 2, -1, -1) && is(i + 2, j    , -1,  1);
    }
    cout << res << endl;
}


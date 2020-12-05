#include "../template.cc"

void solve() {
    vector<bool> v(128*8*2);
    getInp([&](auto& cin, int) {
        char c;
        int rowL = 0, rowR = 127;
        F0R(_, 7) {
            cin >> c;
            if(c == 'B')
                rowL = (rowL + rowR + 1)/2;
            else
                rowR = (rowL + rowR + 1)/2;
        }
        int colL = 0, colH = 7;
        F0R(_, 3) {
            cin >> c;
            if(c == 'R')
                colL = (colL + colH + 1)/2;
            else
                colH = (colL + colH + 1)/2;
        }
        v[rowL*8 + colL] = true;
    });

    FOR(i, 1, SZ(v) - 1)
        if(v[i - 1] && !v[i] && v[i + 1])
            cout << i << endl;
}


#include "../template.cc"

void solve() {
    ll res = 0;

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
        ckmax(res, rowL*8LL + colL);
    });

    cout << res << endl;
}


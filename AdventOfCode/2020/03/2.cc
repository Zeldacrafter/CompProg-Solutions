#include "../template.cc"

void solve() {
    vector<string> ss = getInp();

    int w = SZ(ss[0]);
    int h = SZ(ss);

    auto calc = [&](int dx, int dy) {
        ll amt = 0;
        for(int y = dy, x = dx; y < h; y += dy, x = (x + dx) % w)
            amt += ss[y][x] == '#';
        return amt;
    };

    cout << calc(1, 1)*calc(3, 1)*calc(5, 1)*calc(7, 1)*calc(1, 2) << endl;
}

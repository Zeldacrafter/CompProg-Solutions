#include "../template.cc"

void solve() {
    vector<string> ss;
    getInp([&](auto& cin, int i) {
        ss.eb();
        cin >> ss.back();
    });

    int w = SZ(ss[0]);
    int h = SZ(ss);

    ll res = 0;
    for(int y = 1, x = 3; y < h; y++, x = (x + 3) % w)
        res += ss[y][x] == '#';
    cout << res << endl;
}

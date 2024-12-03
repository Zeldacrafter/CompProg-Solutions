#include "../utils.cc"

void solve() {
    ll res = 0;

    getInp([&](auto& cin, int) {
        string s; char _; ll x, y;
        while(cin >> s) {
            stringstream in(s);
            in >> _ >> _ >> _ >> _ >> x >> _ >> y;
            res += x*y;
        }
    }, "mul\\([0-9]*,[0-9]*\\)", true);

    cout << res << endl;
}


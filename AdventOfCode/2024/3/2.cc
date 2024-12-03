#include "../utils.cc"

void solve() {
    ll res = 0;
    bool active = true;
    getInp([&](auto& cin, int) {
        string s; char _; ll x, y;
        while(cin >> s) {
            if(s == "do()") {
                active = true;
            } else if(s == "don't()") {
               active = false;
           } else if(active) {
                stringstream in(s);
                in >> _ >> _ >> _ >> _ >> x >> _ >> y;
                res += x*y;
            }
        }
    }, "mul\\([0-9]*,[0-9]*\\)|do\\(\\)|don't\\(\\)", true);

    cout << res << endl;
}


#include "../template.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int i) {
            int a, b;
            char c, ch;
            string s;
            cin >> a >> c >> b >> ch >> c >> s;
            int amt = 0;
            if(s[a - 1] == ch) amt++;
            if(s[b - 1] == ch) amt++;
            if(amt == 1) res++;
    });
    cout << res << endl;
}

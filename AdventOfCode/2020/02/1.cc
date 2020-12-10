#include "../template.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int i) {
            int a, b;
            char c, ch;
            string s;
            cin >> a >> c >> b >> ch >> c >> s;
            int amt = count(ALL(s), ch);
            if(amt <= b && amt >= a) res++;
    });
    cout << res << endl;
}

#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        string s; bool outp = false;
        while(cin >> s) {
            if(s == "|")
                outp = true;
            else if(outp && (SZ(s) == 2 || SZ(s) == 4 || SZ(s) == 3 || SZ(s) == 7))
                res++;
        }
    });
    cout << res << endl;
}


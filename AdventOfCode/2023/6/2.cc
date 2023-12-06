#include "../utils.cc"

void solve() {
    ll t = 0, d = 0;
    getInp([&](auto& cin, int i) {
        string s; char k; cin >> s;
        if(!i) {
            while(cin >> k) if(isdigit(k)) t = t*10 + k - '0';
        } else {
            while(cin >> k) if(isdigit(k)) d = d*10 + k - '0';
        }
    });

    ll res = 1;
    F0R(j, t + 1) res += j*(t - j) > d;
    cout << res << endl;
}


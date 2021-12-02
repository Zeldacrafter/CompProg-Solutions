#include "../utils.cc"

void solve() {
    ll h = 0, d = 0;
    getInp([&](auto& cin, int) {
        string s; int k; cin >> s >> k; 

        if(s[0] == 'f')
            h += k;
        else if(s[0] == 'd')
            d += k;
        else if(s[0] == 'u')
            d -= k;
    });

    cout << h*d << endl;
}


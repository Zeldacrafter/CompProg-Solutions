#include "../utils.cc"

void solve() {
    ll h = 0, d = 0, aim = 0;
    getInp([&](auto& cin, int) {
        string s; int k; cin >> s >> k; 

        if(s[0] == 'f')
            h += k, d += aim*k;
        else if(s[0] == 'd')
            aim += k;
        else if(s[0] == 'u')
            aim -= k;
    });

    cout << h*d << endl;
}


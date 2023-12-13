#include "../utils.cc"

void solve() {
    vector<vector<string>> inp = {{}};
    getInp([&](auto& cin, int) {
        string s;
        if(cin >> s) inp.back().pb(s);
        else inp.eb();
    });

    ll res = 0;
    for(const vector<string>& lava : inp) {
        F0R(i, SZ(lava) - 1) {
            int amtWrong = 0;
            F0R(r, i + 1)
                F0R(c, SZ(lava[0]))
                    if(i + 1 + r < SZ(lava))
                        amtWrong += lava[i - r][c] != lava[i + 1 + r][c]; 
            if(amtWrong == 1) res += 100*(i + 1);
        }
        F0R(i, SZ(lava[0]) - 1) {
            int amtWrong = 0;
            F0R(c, i + 1)
                F0R(r, SZ(lava))
                    if(i + 1 + c < SZ(lava[0]))
                        amtWrong += lava[r][i - c] != lava[r][i + 1 + c]; 
            if(amtWrong == 1) res += i + 1;
        }
    }
    cout << res << endl;
}


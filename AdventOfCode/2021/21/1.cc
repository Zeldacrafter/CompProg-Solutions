#include "../utils.cc"

void solve() {
    int p1 = -1, p2 = -1;
    getInp([&](auto& cin, int) {
        string s; cin >> s >> s >> s >> s >> (p1 == -1 ? p1 : p2);
    });

    int d = 1, s1 = 0, s2 = 0;
    int amt = 0;
    bool turn1 = true;
    while(s1 < 1000 && s2 < 1000) {
        int rolled = 0;
        F0R(_, 3) {
            rolled += d++;
            if(d == 101) d = 1;
            amt++;
        }
        if(turn1) {
            p1 = (p1 + rolled - 1) % 10 + 1;
            s1 += p1;
        } else {
            p2 = (p2 + rolled - 1) % 10 + 1;
            s2 += p2;
        }
        turn1 ^= 1;
    }

    cout << min(s1, s2) * amt << endl;
}


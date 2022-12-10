#include "../utils.cc"

void solve() {
    set<int> coords;
    ll cycle = 0, reg = 1;

    getInp([&](auto& cin, int) {
        string s; cin >> s;

        if(abs(cycle % 40 - reg) <= 1) coords.insert(cycle);
        cycle++;
        

        if(s == "addx") {
            ll val; cin >> val;

            if(abs(cycle % 40 - reg) <= 1) coords.insert(cycle);
            cycle++;
            reg += val;
        }
    });

    F0R(i, 40*6) {
        if(i % 40 == 0) cout << endl;
        cout << (coords.count(i) ? '#' : ' ');
    }
}


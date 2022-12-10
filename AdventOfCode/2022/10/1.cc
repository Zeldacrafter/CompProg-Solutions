#include "../utils.cc"

const set<int> cycles = {20, 60, 100, 140, 180, 220};

void solve() {
    ll res = 0;
    ll cycle = 0, reg = 1;

    getInp([&](auto& cin, int) {
        string s; cin >> s;

        cycle++;
        if(cycles.count(cycle)) res += cycle * reg;

        if(s == "addx") {
            ll val; cin >> val;

            cycle++;
            if(cycles.count(cycle)) res += cycle * reg;
            reg += val;
        }
    });

    cout << res << endl;
}


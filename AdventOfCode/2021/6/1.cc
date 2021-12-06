#include "../utils.cc"

void solve() {
    vector<ll> inp(9);
    getInp([&](auto& cin, int) {
        int k; char c;
        do {
            cin >> k;
            inp[k]++;
        } while(cin >> c);
    });

    F0R(i, 80) {
        vector<ll> inpNew(9);
        inpNew[6] = inpNew[8] = inp[0];
        FOR(i, 1, SZ(inp)) inpNew[i - 1] += inp[i];
        inp = inpNew;
    }

    cout << accumulate(ALL(inp), 0ll) << endl;
}


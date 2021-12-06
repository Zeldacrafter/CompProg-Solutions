#include "../utils.cc"
#include "static_matrix.cc"

// Solution in log(iterations)
void solve() {
    vector<ll> inp(9);
    getInp([&](auto& cin, int) {
        int k; char c;
        do {
            cin >> k;
            inp[k]++;
        } while(cin >> c);
    });

    matrix<9, ll> m{};
    F0R(i, 9) m[(i + 1) % 9][i] = 1;
    m[0][6] = 1;

    m = m.pow(80);

    ll res = 0;
    F0R(r, SZ(m)) F0R(c, SZ(m)) res += inp[r]*m[r][c];
    cout << res << endl;
}


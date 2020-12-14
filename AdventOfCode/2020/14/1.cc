#include "../template.cc"

const int MAXN = 1e6;

ll setN(ll& n, ll val, int bit) {
    return (n & ~(1ll << bit)) | (val << bit);
}

void solve() {

    vector<ll> mem(MAXN);
    string mask;

    getInp([&](auto& cin, int) {
        char c, _;
        cin >> _ >> c >> _ >> _;
        if(c == 'a') {
            string s;
            cin >> s >> mask;
            reverse(ALL(mask));
        } else {
            assert(c == 'e');
            ll addr, val;
            cin >> addr >> _ >> _ >> val;

            F0R(i, SZ(mask))
                if(mask[i] == 'X')
                    val = setN(val, (val >> i) & 1, i);
            mem[addr] = val;
        }
    });

    cout << accumulate(ALL(mem), 0LL) << endl;
}


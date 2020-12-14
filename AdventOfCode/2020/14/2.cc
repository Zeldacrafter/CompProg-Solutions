#include "../template.cc"

ll setN(ll n, ll val, int bit) {
    return (n & ~(1ll << bit)) | (val << bit);
}

void solve() {

    map<ll, ll> mem;
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

            ll subSets = 0;
            F0R(i, SZ(mask)) {
                if(mask[i] == 'X')
                    subSets |= 1ll << i;
                else 
                    addr |= (ll)(mask[i] - '0') << i;
            }

            for(ll k = subSets; ; --k &= subSets) {
                ll newAddr = addr;
                F0R(i, SZ(mask))
                    if((subSets >> i) & 1)
                        newAddr = setN(newAddr, (k >> i) & 1, i);
                mem[newAddr] = val;

                if(!k) break;
            }
        }
    });

    ll res = 0;
    for(auto [k, v] : mem)
        res += v;
    cout << res << endl;
}


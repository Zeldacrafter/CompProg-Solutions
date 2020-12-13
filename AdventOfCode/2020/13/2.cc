#include "../template.cc"

ll pow(ll base, ll exp, ll MOD) {
    ll res = 1;
    base %= MOD;
    for (; exp; exp >>= 1, base = (base * base) % MOD)
        if (exp & 1) 
            res = (res * base) % MOD;
    return res;
}

ll mulInv(ll a, ll MOD) {
    return pow(a, MOD - 2, MOD); 
}

ll chineseRemainder(vi mods, vi rems) {
    assert(SZ(mods) == SZ(rems));

    ll prod = 1;
    F0R(i, SZ(mods)) prod *= mods[i];

    ll res = 0;
    F0R(i, SZ(mods)) {
        ll p = prod / mods[i];
        res += rems[i] * mulInv(p, mods[i]) * p;
    }

    return res % prod;
}

void solve() {
    ll amt;
    cin >> amt;
    string s;
    cin >> s;
    vector<string> inp = split(s, ",");

    vi num, rem;
    F0R(i, SZ(inp))
        if (inp[i] != "x") {
            ll val = stoi(inp[i]);
            num.pb(val);
            rem.pb((-i % val) + val);
        }

    cout << chineseRemainder(num, rem) << endl;
}


#include "../utils.cc"

ll next(ll num) {
    num ^= num * 64;
    num %= 16777216ll;
    num ^= num / 32;
    num %= 16777216ll;
    num ^= num * 2048;
    num %= 16777216ll;
    return num;
}

void solve() {
    map<vi, ll> profit;
    getInp([&](auto& cin, int) {
        ll k; cin >> k;

        vi changes;
        set<vi> seen;
        F0R(_, 2000) {
            ll k2 = next(k);
            changes.pb(k2 % 10 - k % 10);
            if(SZ(changes) >= 4) {
                vi seq(changes.end() - 4, changes.end());
                if(seen.insert(seq).se) profit[seq] += k2 % 10;
            }
            k = k2;
        }
    });

    ll res = 0;
    for(auto [_, v] : profit) ckmax(res, v);
    cout << res << endl;
}


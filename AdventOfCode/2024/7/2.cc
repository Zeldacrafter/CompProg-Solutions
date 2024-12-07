#include "../utils.cc"

bool is_ok(ll val, vi& a, ll curr = 0, int i = 0) {
    if(i == SZ(a)) return val == curr;

    return is_ok(val, a, curr + a[i], i + 1) 
        || is_ok(val, a, curr * a[i], i + 1) 
        || is_ok(val, a, stoll(to_string(curr) + to_string(a[i])), i + 1);
}

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        ll val, y; vi a; char _;
        cin >> val >> _;
        while(cin >> y) a.pb(y);
        if(is_ok(val, a)) res += val;
    });
    cout << res << endl;
}

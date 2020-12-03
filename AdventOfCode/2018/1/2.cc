#include "../template.cc"

void solve() {
    vi a;
    getInp([&](auto& cin, int i) {
        a.eb();
        cin >> a.back();
    });

    ll res = 0;
    set<ll> seen;
    seen.insert(0);
    for(int i = 0;; ++i) {
        res += a[i % SZ(a)];
        if(!seen.insert(res).se) {
            cout << res << endl;
            return;
        }
    }
    
}



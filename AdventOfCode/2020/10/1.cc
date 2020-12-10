#include "../template.cc"

void solve() {
    vector<ll> a;
    getInp([&](auto& cin, int) {
        int k;
        cin >> k;
        a.pb(k);
    });

    a.pb(0);
    sort(ALL(a));
    a.pb(a[SZ(a) - 1] + 3);

    vi cnt(4);
    F0R(i, SZ(a) - 1)
        cnt[a[i + 1] - a[i]]++;
    cout << cnt[1]*cnt[3] << endl;
}

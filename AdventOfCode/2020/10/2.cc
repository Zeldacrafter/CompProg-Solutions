#include "../template.cc"

const int MAXN = 300;
void solve() {
    ll start = 0;
    vector<ll> res(MAXN), seen(MAXN);
    vector<string> ss = getInp([&](auto& cin, int) {
        ll k;
        cin >> k;
        assert(!seen[k]);
        seen[k] = true;
        ckmax(start, k);
    });
    start += 3;

    seen[0] = seen[start] = true;

    res[start] = 1;
    for(int i = start - 1; ~i; --i)
        if(seen[i])
            res[i] = res[i + 1] + res[i + 2] + res[i + 3];
    cout << res[0] << endl;
}

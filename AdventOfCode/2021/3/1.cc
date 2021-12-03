#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();
    int n = SZ(ss[0]);

    vector<ll> cnt0(n), cnt1(n);
    for(string& s : ss) F0R(i, n) {
        if(s[i] == '0') cnt0[i]++;
        if(s[i] == '1') cnt1[i]++;
    }

    ll res1 = 0, res2 = 0;
    F0R(i, n) {
        res1 = res1*2 + (cnt1[i] <= cnt0[i]);
        res2 = res2*2 + (cnt1[i] >= cnt0[i]);
    }

    cout << res1*res2 << endl;
}


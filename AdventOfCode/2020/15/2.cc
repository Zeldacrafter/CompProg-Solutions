#include "../template.cc"

const int MAXN = 30000000;

void solve() {
    vector<string> ss = getInp();
    vector<string> numStr = split(ss[0], ",");
    vi a;
    for(string& s : numStr)
        a.pb(stoi(s));

    map<ll, ll> lastSpoken;
    ll lastInterval = 0;
    F0R(t, MAXN - 1) {
        ll nextNum = t < SZ(a) ? a[t] : lastInterval;
        lastInterval = lastSpoken.count(nextNum)*(t - lastSpoken[nextNum]);
        lastSpoken[nextNum] = t;
    }
    cout << lastInterval << endl;
}

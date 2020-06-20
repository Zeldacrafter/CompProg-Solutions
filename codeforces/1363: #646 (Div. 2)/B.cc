#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }

void solve() {
    string s;
    cin >> s;
    int n = SZ(s);

    int cnt0 = 0, cnt1 = 0;
    F0R(i, n) {
        if(s[i] == '1') cnt1++;
        else cnt0++;
    }

    int best = min(cnt0, cnt1);
    int ones = 0, zeroes = 0;
    F0R(i, n - 1) {
        if(s[i] == '1') ones++;
        else zeroes++;

        ckmin(best, ones + cnt0 - zeroes);
        ckmin(best, zeroes + cnt1 - ones);
    }

    cout << best << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


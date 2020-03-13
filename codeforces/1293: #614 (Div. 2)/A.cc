#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()

void solve() {
    int floors, curr, closedAmt, f;
    cin >> floors >> curr >> closedAmt;

    vi closed;
    F0R(i, closedAmt) {
        cin >> f;
        closed.pb(abs(f - curr));
    }

    sort(ALL(closed));

    if(closed[0]) {
        cout << 0 << endl;
        return;
    }

    int i = 1;
    int val = 1;
    while(i < SZ(closed)) {
        int cnt = 0;
        while(i < SZ(closed) && closed[i] == val) {
            ++i;
            ++cnt;
        }

        int lim = curr - val <= 0 || curr + val > floors ? 1 : 2;
        if(cnt != lim) {
            cout << val << endl;
            return;
        }
        val++;
    }

    cout << val << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--)
        solve();

    return 0;
}

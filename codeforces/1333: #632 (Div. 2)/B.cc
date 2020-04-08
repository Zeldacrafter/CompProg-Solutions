#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    cin >> n;

    vi a(n);
    int pos = n, neg = n;
    F0R(i, n) {
        cin >> a[i];
        if(pos == n && a[i] == 1) pos = i;
        if(neg == n && a[i] == -1) neg = i;
    }
    bool ok = true;
    F0R(i, n) {
        int k;
        cin >> k;
        if(a[i] > k)
            if(neg >= i)
                ok = false;
        if(a[i] < k)
            if(pos >= i)
                ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}



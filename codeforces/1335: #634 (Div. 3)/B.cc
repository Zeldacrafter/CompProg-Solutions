#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    F0R(i, a)
        s.pb('a' + min(i, b - 1));

    F0R(i, n)
        cout << s[i % a];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


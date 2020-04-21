#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    cin >> n;

    if(n == 2 || (n / 2) & 1) {
        cout << "NO\n"; 
        return;
    }

    cout << "YES\n";
    F0R(i, n/2)
        cout << (i+1)*2 << ' ';
    F0R(i, n/2 - 1)
        cout << i*2 + 1 << ' ';
    cout << n + n/2 - 1 << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


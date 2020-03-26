#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string a(n, '?'), b(n, '?');
    bool insA = false;
    F0R(i, n) {
        if(s[i] == '0') {
            a[i] = b[i] = '0';
        } else if (s[i] == '2') {
            if(insA) {
                a[i] = '0';
                b[i] = '2';
            } else
                a[i] = b[i] = '1';
        } else {
            if(!insA) {
                insA = true;
                a[i] = '1';
                b[i] = '0';
            } else {
                a[i] = '0';
                b[i] = '1';
            }
        }
    }
    cout << a << endl << b << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


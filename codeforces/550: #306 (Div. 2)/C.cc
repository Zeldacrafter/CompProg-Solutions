#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    int n = SZ(s);
    F0R(a, n) {
        int d1 = s[a] - '0';
        int sum = d1;
        if(sum % 8 == 0) {
            cout << "YES\n" << sum ;
            return 0;
        }
    }
    F0R(a, n) FOR(b, a + 1, n) {
        int d1 = s[a] - '0';
        int d2 = s[b] - '0';
        int sum = d1*10 + d2;
        if(sum % 8 == 0) {
            cout << "YES\n" << sum ;
            return 0;
        }
    }
    F0R(a, n) FOR(b, a + 1, n) FOR(c, b + 1, n) {
        int d1 = s[a] - '0';
        int d2 = s[b] - '0';
        int d3 = s[c] - '0';
        int sum = d1*100 + 10*d2 + d3;
        if(sum % 8 == 0) {
            cout << "YES\n" << sum ;
            return 0;
        }
    }
    cout << "NO\n";
}

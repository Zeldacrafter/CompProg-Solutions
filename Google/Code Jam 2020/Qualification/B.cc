#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

string solve(string s, int d) {
    if(s == "") return "";

    F0R(i, SZ(s)) {
        if(s[i] - d == '0') {
            string res = "";
            if(i > 0)
                res += '(' + solve(s.substr(0, i), d + 1) + ')';
            res += s[i] + solve(s.substr(i + 1), d);
            return res;
        }
    }
    return '(' + solve(s, d + 1) + ')';
}

int main() {

    int tcc;
    string s;
    cin >> tcc;

    FOR(tc, 1, tcc + 1) {
        cin >> s;
        cout << "Case #" << tc << ": " << solve(s, 0) << endl;
    }
}


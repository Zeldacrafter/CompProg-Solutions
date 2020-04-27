// this line is here for a reason
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))


void solve() {
    string s;
    cin >> s;

    bool allSame = true;
    char sameC = s[0];
    for(char c : s) {
        if(c != sameC) {
            allSame = false;
            break;
        }
    }

    if(allSame) {
        cout << s << endl;
        return;
    }

    string res;
    res.pb(s[0]);
    FOR(i, 1, SZ(s)) {
        if(s[i] == res[SZ(res) - 1])
            res.pb(s[i] == '1' ? '0' : '1');
        res.pb(s[i]);
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


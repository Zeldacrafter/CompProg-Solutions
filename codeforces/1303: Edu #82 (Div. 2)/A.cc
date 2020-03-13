#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define SZ(x) (x).size()
#define endl '\n'

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;

        int l = 0;
        while(s[l] == '0' && l < SZ(s))
            l++;

        if(l == SZ(s)) {
            cout << 0 << endl;
            continue;
        }

        int r = SZ(s) - 1;
        while(s[r] == '0')
            r--;

        int cnt = 0;
        FOR(i, l, r + 1)
            if(s[i] == '0')
                cnt++;
        cout << cnt << endl;
    }

    return 0;
}

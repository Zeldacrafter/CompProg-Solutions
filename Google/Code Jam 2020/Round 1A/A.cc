#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

void solve() {
    int n;
    cin >> n;

    string start, mid, end, s;
    bool ok = true;
    F0R(i, n) {
        cin >> s;
        if(!ok) continue;

        int l = 0;
        for(; l < SZ(s) && s[l] != '*'; ++l);
        int r = SZ(s) - 1;
        for(; ~r && s[r] != '*'; --r);

        for(int i = 0; ok && i < l; ++i) {
            if(SZ(start) < i + 1)
                start.pb(s[i]);
            else if(start[i] != s[i])
                ok = false;
        }

        for(int i = SZ(s) - 1, j = 0; ok && i > r; --i, ++j) {
            if(SZ(end) < SZ(s) - i)
                end.pb(s[i]);
            else if(end[j] != s[i])
                ok = false;
        }

        if(!ok) continue;

        while(++l < r)
            if(s[l] != '*')
                mid.pb(s[l]);
    }

    if(!ok) {
        cout << '*' << endl;
    } else {
        reverse(ALL(end));
        cout << start << mid << end << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}


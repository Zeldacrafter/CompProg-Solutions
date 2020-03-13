#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define SZ(x) (x).size()
#define endl '\n'

bitset<26> seen;
array<char, 100> kb;

void solve(string& s) {
    seen.reset();
    kb.fill(0);

    int pos = 27;
    kb[pos] = s[0];
    seen[s[0] - 'a'] = true;
    FOR(i, 1, SZ(s)) {
        if(seen[s[i] - 'a']) {
            if(kb[pos - 1] == s[i])
                pos--;
            else if(kb[pos + 1] == s[i])
                pos++;
            else {
                cout << "NO\n";
                return;
            }
        } else {
            if(!kb[pos - 1])
                pos--;
            else if(!kb[pos + 1])
                pos++;
            else {
                cout << "NO\n";
                return;
            }
            seen[s[i] - 'a'] = true;
            kb[pos] = s[i];
        }
    }

    cout << "YES\n";
    F0R(i, 26)
        if(!seen[i])
            cout << (char)(i + 'a');

    int i = 0;
    while(!kb[i]) i++;

    while(kb[i])
        cout << kb[i++];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}

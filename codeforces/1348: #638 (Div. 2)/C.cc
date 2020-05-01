#include <bits/stdc++.h>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define CEIL(a, b) ((a) + (b)-1) / (b)

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    sort(ALL(s));

    if(n == k || s[0] != s[k - 1])
        cout << s[k - 1] << endl;
    else if(s[k] == s[n - 1])
        cout << s[0] << string(CEIL(n, k) - 1, s[k]) << endl;
    else
        cout << s[0] << s.substr(k) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


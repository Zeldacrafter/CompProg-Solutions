#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

bitset<(int)2e5> checked;

int n, k;
string s;
int same[26];
void getSames(int i) {
    if(i >= n || i < 0 || checked[i])
        return;

    checked[i] = true;
    same[s[i] - 'a']++;

    getSames(i + k);
    getSames(i - k);
    getSames(n - i - 1);
}

void solve() {
    checked.reset();
    cin >> n >> k >> s;

    ll res = 0;
    F0R(i, n - k + 1) {
        if(checked[i])
            continue;

        CLR(same, 0);
        getSames(i);

        int mx = 0;
        F0R(i, 26) {
            res += same[i];
            ckmax(mx, same[i]);
        }
        res -= mx;
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


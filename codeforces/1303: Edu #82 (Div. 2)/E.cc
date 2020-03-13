#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define ROF(a, b, c) for(auto (a) = (b); (a) >= (c); --(a))
#define R0F(a, b) ROF(a, b, 0)
#define SZ(x) (x).size()
#define endl '\n'
void ckMin(int& a, int b) { a = min(a, b); }

int n;
int nextInd[410][26];
int dp[410][410];

bool check(string s1, string s2) {
    dp[0][0] = -1;
    F0R(i, SZ(s1) + 1) {
        F0R(j, SZ(s2) + 1) {
            if(!i && !j)
                continue;
            
            dp[i][j] = n;
            if(i)
                ckMin(dp[i][j], nextInd[dp[i - 1][j] + 1][s1[i - 1] - 'a']);
            if(j)
                ckMin(dp[i][j], nextInd[dp[i][j - 1] + 1][s2[j - 1] - 'a']);
        }
    }

    return dp[SZ(s1)][SZ(s2)] < n;
}

void solve() {
    string from, to;
    cin >> from >> to;
    n = SZ(from);

    F0R(i, 26) {
        nextInd[n][i] = n;
        nextInd[n + 1][i] = n;
    }
    R0F(i, n - 1) {
        memcpy(nextInd[i], nextInd[i+1], sizeof(nextInd[0]));
        nextInd[i][from[i] - 'a'] = i;
    }

    F0R(len1, SZ(to)) {
        if(check(to.substr(0, len1), to.substr(len1))) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();

    return 0;
}

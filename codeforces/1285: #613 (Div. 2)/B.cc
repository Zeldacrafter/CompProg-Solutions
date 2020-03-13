#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
 
int score[100010];

void solve() {
    int n;
    cin >> n;

    F0R(i, n)
        cin >> score[i];

    ll sum = 0;
    F0R(i, n) {
        sum += score[i];
        if(sum <= 0) {
            cout << "NO\n";
            return;
        }
    }

    sum = 0;
    for(int i = n - 1; i >= 0; --i) {
        sum += score[i];
        if(sum <= 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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

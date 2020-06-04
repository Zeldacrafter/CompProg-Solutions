#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define CEIL(a, b) ((a) + (b)-1) / (b)

void solve() {
    ll a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << endl;
        return;
    }

    int cnt = 0;
    if(a > b) {
        while(a && a > b && (a & 1) == 0) {
            a >>= 1;
            cnt++;
        }
    } else {
        while(a < b && cnt < 63) {
            a <<= 1;
            cnt++;
        }
    }
    if(a == b) 
        cout << CEIL(cnt, 3) << endl;
    else
        cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


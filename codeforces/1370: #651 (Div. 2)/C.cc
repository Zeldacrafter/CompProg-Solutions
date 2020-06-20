#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

const string p1 = "Ashishgup", p2 = "FastestFinger";

void solve() {
    ll n;
    cin >> n;

    ll cnt = 0, k = n;
    while(!(k & 1)) {
        k >>= 1;
        cnt++;
    }

    if(k == 1) {
        cout << (cnt == 1 ? p1 : p2) << endl;
    } else if(cnt == 1) {
        int otherFacs = 0;
        for(int i = 3; i*i <= k; i += 2) {
            while(k % i == 0) {
                k /= i;
                otherFacs++;
            }
        }
        if(k > 1) otherFacs++;
        cout << (otherFacs == 1 ? p2 : p1) << endl;
    } else {
        cout << p1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


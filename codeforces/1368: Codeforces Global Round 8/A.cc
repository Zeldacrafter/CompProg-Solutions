#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void solve() {
    ll a, b, n;

    cin >> a >> b >> n;

    ll sum = max(a, b), sum1 = min(a, b);
    int i = 0;
    while(sum <= n) {
        swap(sum, sum1);
        sum += sum1;
        i++;
    }
    cout << i << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


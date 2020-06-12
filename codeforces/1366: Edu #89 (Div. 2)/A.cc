#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll a, b;
    cin >> a >> b;

    if(b > a) swap(a, b);

    ll diff = a - b;

    ll made = min({diff, b, a - diff});
    a -= made*2;
    b -= made;

    made += min(a, b)*2/3;
    cout << made << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


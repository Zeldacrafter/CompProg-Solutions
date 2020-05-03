#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll x;
    cin >> x;

    ll cnt = 0;
    for(ll curr = 100; curr < x; ++cnt)
        curr += curr/100;
    cout << cnt << endl;
}



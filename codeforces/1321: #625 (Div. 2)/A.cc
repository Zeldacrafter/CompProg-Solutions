#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

bitset<101> bs;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n;
    F0R(i, n) {
        cin >> k;
        bs[i] = k;
    }

    ll me = 0, him = 0;
    F0R(i, n) {
        cin >> k;
        if(k && !bs[i]) him++;
        if(!k && bs[i]) me++;
    }

    if(!me) 
        cout << -1 << endl;
    else
        cout << 1LL + him/me << endl;
}

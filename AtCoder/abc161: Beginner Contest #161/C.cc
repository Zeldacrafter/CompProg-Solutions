#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
template <typename t> bool ckmin(t& a, const t& b) {return a > b ? a = b, true : false;}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;
    n = n % k;
    ll m = n;
    while(n > abs(n - k)) {
        n = abs(n - k);
        ckmin(m, n);
    }
    cout << m << endl;
}



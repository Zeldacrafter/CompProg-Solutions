#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define pb push_back
#define SZ(x) (x).size()

typedef long long ll;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll x;
    cin >> x;
 
    ll resA = 1;
    ll resB = x;
 
    vector<ll> facs;
    for (ll i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            ll fac = 1;
            while(x % i == 0) {
                x /= i;
                fac *= i;
            } 
            facs.pb(fac);
        }
    }
    if (x > 1) 
        facs.pb(x);
 
    for (int i = 0; i < (1 << SZ(facs)); ++i) {
        ll a = 1;
        ll b = 1;
 
        for (int p = 0; p < SZ(facs); ++p) {
            if (i & (1 << p)) 
                a *= facs[p];
            else 
                b *= facs[p];
        }
        
        if (max(a, b) < max(resA, resB)) {
            resA = a;
            resB = b;
        }
    }
 
    cout << resA << ' ' << resB << endl;
}

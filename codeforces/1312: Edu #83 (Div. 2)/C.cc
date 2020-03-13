#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define SZ(x) (x).size()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) for(auto (a) = (b); ~(a); --(a)) 
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<ll> ar(n);
    ll m = 0;
    F0R(i, n) {
        cin >> ar[i];
        ckmax(m, ar[i]);
    }

    vector<ll> poss;
    vector<bool> used;
    ll curr = 1;
    while(curr <= m) {
        used.pb(false);
        poss.pb(curr);
        curr *= k;
    }

    F0R(i, n) {
        R0F(p, SZ(poss) - 1) {
            if(!ar[i]) break;
            if(!used[p] && ar[i] >= poss[p]) {
                ar[i] -= poss[p];
                used[p] = true;
            }
        }
        if(ar[i]) {
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
}


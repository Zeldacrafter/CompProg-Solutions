#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

bitset<101> bs;
void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    F0R(i, n) 
        cin >> a[i];

    bs.reset();
    vi res;
    for(int x : a) {
        if(!bs[x]) {
            bs[x] = true;
            res.pb(x);
        }
    }

    if(SZ(res) > k) {
        cout << -1 << endl;
        return;
    }

    for(int j = 0; SZ(res) < k; ++j)
        res.pb(res[j]);

    F0R(i, n - 1)
        F0R(j, k)
            res.pb(res[j]);
   
    cout << SZ(res) << endl;
    for(int x : res)
        cout << x << ' ';
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


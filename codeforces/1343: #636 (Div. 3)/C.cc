#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    F0R(i, n)
        cin >> a[i];

    ll sum = 0;
    bool pos = a[0] > 0;
    int best = a[0];
    for(int k : a) {
        if((k > 0) == pos) {
            ckmax(best, k);
        } else {
            sum += best;
            pos = k > 0;
            best = k;
        }
    }
    sum += best;
    
    cout << sum << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


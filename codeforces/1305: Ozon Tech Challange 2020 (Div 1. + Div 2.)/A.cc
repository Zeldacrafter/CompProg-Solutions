#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        
        vi a(n), b(n);
        
        F0R(i, n) cin >> a[i];
        F0R(i, n) cin >> b[i];

        sort(ALL(a));
        sort(ALL(b));

        F0R(i, n) cout << a[i] << " \n"[i==n-1];
        F0R(i, n) cout << b[i] << " \n"[i==n-1];
    }
}

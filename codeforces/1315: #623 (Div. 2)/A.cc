#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define endl '\n'

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;

        ll x2 = a - x - 1;
        ll y2 = b - y - 1;
        cout << max( max(y * a, y2 * a), max(x * b, x2 * b) ) << endl;

    }
}

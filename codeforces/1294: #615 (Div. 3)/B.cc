#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR((a), 0, (b))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()

void solve() {
    int n, x, y;
    cin >> n;

    vii pts(n, mp(-1, -1));
    F0R(i, n) {
        cin >> x >> y;
        pts[i] = ii(x, y);
    }

    sort(ALL(pts));

    string s = "";
    x = 0;
    y = 0;
    for(auto [a, b] : pts) {
        if(x > a || y > b) {
            cout << "NO\n";
            return;
        }
        F0R(i, a - x)
            s = s + 'R';
        F0R(i, b - y)
            s = s + 'U';
        x = a;
        y = b;
    }
    cout << "YES\n" << s << endl;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while(tc--)
        solve();

}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (x).size()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) for (auto(a) = 0; (a) < (b); ++(a))
#define R0F(a, b) for (auto(a) = (b); (a) >= 0; --(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))
#define ROFI(a, b) for (auto(a) = (b).rbegin(); (a) != (b).rend(); ++(a))
#define TRAV(a, b) for (auto&(a) : (b))
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

int ceil(int n, int k) {
	return n/k + !!(n % k);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	int tc;
	cin >> tc;

	while(tc--) {
		char c;
		int n, m;
        cin >> c >> n >> m;

		switch(c) {
			case 'r':
			case 'Q':
				cout << min(n, m) << endl;
				break;
			case 'k':
				cout << ceil(m*n, 2) << endl;
				break;
			case 'K':
				cout << ceil(n, 2) * ceil(m, 2) << endl;
				break;
            default:
                assert(false);
		}
	}

    return 0;
}

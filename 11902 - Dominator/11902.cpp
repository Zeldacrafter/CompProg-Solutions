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
#define TRAV(a, b) for (auto &(a) : (b))
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t &a, const t &b) {
  return a > b ? a = b, true : false;
}
template <typename t> bool ckmax(t &a, const t &b) {
  return a < b ? a = b, true : false;
}

bitset<100> adj[100];
bitset<100> dom[100];
bitset<100> seen;
int nodeC;

void dfs(int curr, int ign) {
  seen[curr] = true;

  if (ign == curr)
    return;

  F0R(i, nodeC)
  if (!seen[i] && adj[curr][i])
    dfs(i, ign);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	FOR(t, 1, tc + 1) {
		cin >> nodeC;

		F0R(i, nodeC) {
			F0R(j, nodeC) {
				bool b;
				cin >> b;
				adj[i][j] = b;
			}
		}

		seen.reset();
		dfs(0, -1);
		F0R(i, nodeC)
			F0R(j, nodeC)
				dom[i][j] = seen[j];

		F0R(i, nodeC) {
			seen.reset();
			dfs(i, -1);
			F0R(j, nodeC)
				dom[i][j] = dom[i][j] & seen[j];
		 }

		F0R(i, nodeC) {
			seen.reset();
			dfs(0, i);
			F0R(j, nodeC)
			dom[i][j] = dom[i][j] & ((i == j) | !seen[j]);
		}

		cout << "Case " << t << ":\n";
		F0R(i, nodeC) {
			cout << "+";
			F0R(j, 2 * nodeC - 1)
				cout << "-";
			cout << "+\n|";

			F0R(j, nodeC) 
				cout << (dom[i][j] ? "Y" : "N") << "|";
			cout << endl;
		}
		cout << "+";
		F0R(j, 2 * nodeC - 1)
			cout << "-";
		cout << "+\n";
	}

	return 0;
}

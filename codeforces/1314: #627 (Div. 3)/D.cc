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
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pf push_front
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ge(a, b) get<(b)>((a))
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k, n;
    cin >> n;
    
    vi adj(n);
    F0R(i, n) cin >> adj[i];
    F0R(i, n) {
        cin >> k;
        adj[i] -= k;
    }

    sort(RALL(adj));

    ll cnt = 0;
    F0R(i, n) {
        int curr = adj[i];

        auto it = lower_bound(adj.begin() + i + 1, adj.end(), -curr, greater<int>());
        if(it == adj.end())
            cnt += n - 1 - i;
        else
            cnt += (it - adj.begin()) - i - 1;
    }

    cout << cnt << endl;

}


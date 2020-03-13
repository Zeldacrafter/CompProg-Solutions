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
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }


bitset<1100> done;
int in[1100] = {};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x, y, k;
    cin >> n;

    vvi adj(n+10);
    F0R(i, n - 1) {
        cin >> x >> y;
        x--; y--;

        in[x]++;
        in[y]++;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    while(1) {
        int l1 = -1, l2 = -1, i = 0;
        while(l1 == -1 && i < n) {
            if(!done[i] && in[i] <= 1)
                l1 = i;
            i++;
        }
        while(l2 == -1 && i < n) {
            if(!done[i] && in[i] <= 1)
                l2 = i;
            i++;
        }

        assert(l1 != -1);

        if(l2 == -1) {
            cout << "! " << l1 + 1 << endl;
            return 0;
        }

        cout << "? " << l1 + 1 << ' ' << l2 + 1 << endl;
        cout.flush();

        cin >> k;
        k--;

        if(k == l1 || k == l2) {
            cout << "! " << k + 1 << endl;
            return 0;
        }

        done[l1] = true; in[l1]--;
        done[l2] = true; in[l2]--;
        for(int v : adj[l1]) in[v]--;
        for(int v : adj[l2]) in[v]--;
    }
}

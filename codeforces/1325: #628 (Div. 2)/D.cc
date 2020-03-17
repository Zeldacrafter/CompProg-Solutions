#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

    ll u, v;
    cin >> u >> v;


    if(!u && !v) {
        cout << 0 << endl;
        return 0;
    }

    if(u == v) {
        cout << 1 << endl << u << endl;
        return 0;
    }

    ll k = v - u;

    if(k < 0 || (k & 1) == 1) {
        cout << -1 << endl;
        return 0;
    }

    if( (~(k >> 1ULL) & u) == u ) {
        cout << 2 << endl;
        cout << (u | (k >> 1ULL)) << ' ' << (k >> 1ULL) << endl;
    } else {
        cout << 3 << endl;
        cout << u << ' ' << (k >> 1ULL) << ' ' << (k >> 1ULL) << endl;
    }

}


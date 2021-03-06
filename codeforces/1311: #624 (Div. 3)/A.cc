
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define ROF(a, b, c) for(auto (a) = (b); (a) >= (c); --(a))
#define R0F(a, b) ROF(a, b, 0)
#define pb push_back
#define eb emplace_back
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define fst first
#define snd second
template <typename T>
void ckMin(T& a, T b) { a = min(a, b); }
template <typename T>
void ckMax(T& a, T b) { a = max(a, b); }


void solve() {
    int a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << endl;
        return;

    }
    if(a > b) {
        if((a & 1) == (b & 1))
            cout << 1 << endl;
        else
            cout << 2 << endl;
        return;
    }

    
    if((a & 1) == (b & 1))
        cout << 2 << endl;
    else
        cout << 1 << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--)
        solve();
}

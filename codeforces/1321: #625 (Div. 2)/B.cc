#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define fi first
#define se second
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <typename t>
bool ckmax(t& a, const t& b) {
  return a < b ? a = b, true : false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, b;
    cin >> n;
    
    vii arr;
    F0R(i, n) {
        cin >> b;
        arr.eb(b - i, b);
    }

    sort(ALL(arr));

    ll res = 0;
    for(int i = 0; i < n; ) {
        ll cnt = 0;
        auto [v, in] = arr[i];
        while(i < n && arr[i].fi == v) {
            cnt += arr[i].se;
            i++;
        }
        ckmax(res, cnt);
    }
    cout << res << endl;
}

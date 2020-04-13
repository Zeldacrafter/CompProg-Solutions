#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

const int MAXN = 2e5 + 5;
const int MAXK = 200;
int amt[MAXK + 1][MAXN];

void solve() {
    int n, inp;
    cin >> n;

    F0R(i, MAXK)
        amt[i][0] = 0;

    vi a(n);
    F0R(i, n) {
        cin >> inp;
        a[i] = inp;
        F0R(j, MAXK + 1)
            amt[j][i + 1] = (inp == j) + amt[j][i];
    }

    int res = 1;
    FOR(k, 1, MAXK + 1) {
        int cnt = 2;
        for(int l = 0, r = n - 1; l < r; cnt += 2, l++, r--) {
            while(l < n && a[l] != k)
                l++;
            while(~r && a[r] != k)
                --r;

            if(l > r)
                break;

            if(l == r)
                cnt--;

            FOR(i, 1, MAXK + 1)
                ckmax(res, amt[i][r] - amt[i][l + 1] + cnt);
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}



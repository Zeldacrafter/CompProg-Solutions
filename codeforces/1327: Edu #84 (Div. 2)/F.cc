#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

const ll MOD = 998244353LL;
const int N = 5e5 + 5;

int oneCnt[N];
ll prefSum[N];
vi lastInSeg[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, m;
    cin >> n >> k >> m;

    vi l(m), r(m), x(m);
    F0R(i, m) {
        cin >> l[i] >> r[i] >> x[i];
        lastInSeg[r[i]].pb(i);
    }

    ll res = 1;
    for(int b = 1; b < (1 << k); b <<= 1) {
        CLR(oneCnt, 0);
        CLR(prefSum, 0);
        
        F0R(i, m)
            if(x[i] & b)
                oneCnt[l[i]]++, oneCnt[r[i] + 1]--;

        prefSum[0] = 1;
        int leftBorder = 0;
        int ones = 0;
        FOR(i, 1, n + 1) {
            ones += oneCnt[i];

            prefSum[i] = prefSum[i - 1];
            if(!ones)
                prefSum[i] += prefSum[i - 1] - (!leftBorder ? 0 : prefSum[leftBorder - 1]);
            prefSum[i] %= MOD;

            for(int ind : lastInSeg[i])
                if(!(x[ind] & b))
                    ckmax(leftBorder, l[ind]);
        }

        res *= (prefSum[n] - (!leftBorder ? 0 : prefSum[leftBorder - 1]) + MOD) % MOD;
        res %= MOD;
    }
    cout << (res + MOD) % MOD << endl;
}

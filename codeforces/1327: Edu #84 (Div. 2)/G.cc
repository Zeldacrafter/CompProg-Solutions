#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

const int MAXN = 1e3 + 7,
          MAXK = 14;
const ll INF = 3e18;

int nxt[MAXN][26], fail[MAXN], nodeCnt;
ll sum[MAXN], dp[MAXN][1 << MAXK];

void insert(string &s, int cost) {
    int curr = 0;
    for (char c : s) {
        if (!nxt[curr][c - 'a'])
            nxt[curr][c - 'a'] = ++nodeCnt;
        curr = nxt[curr][c - 'a'];
    }
    sum[curr] += cost;
}

void build() {
    queue<int> q;
    F0R(i, MAXK)
        if (nxt[0][i])
            q.push(nxt[0][i]);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        F0R(i, MAXK) {
            if (nxt[curr][i]) {
                fail[nxt[curr][i]] = nxt[fail[curr]][i];
                sum[nxt[curr][i]] += sum[nxt[fail[curr]][i]];
                q.push(nxt[curr][i]);
            } else {
                nxt[curr][i] = nxt[fail[curr]][i];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, cost;
    string s;
    cin >> n;
    F0R(i, n) {
        cin >> s >> cost;
        insert(s, cost);
    }
    cin >> s;

    build();

    F0R(i, nodeCnt + 1)
        F0R(j, (1 << MAXK))
            dp[i][j] = -INF;

    dp[0][0] = 0;

    vector<ll> tmp(nodeCnt + 1, 0);
    vi to(nodeCnt + 1);
    iota(ALL(to), 0);

    for (char c : s) {
        if (c == '?') {
            R0F(s, (1 << MAXK) - 1) {
                F0R(p, nodeCnt + 1) {
                    if(dp[p][s] == -INF)
                        continue;
                    F0R(i, MAXK) {
                        if(s >> i & 1)
                            continue;
                        ckmax(dp[nxt[to[p]][i]][s | 1 << i],
                              dp[p][s] + tmp[p] + sum[nxt[to[p]][i]]);
                    }
                    dp[p][s] = -INF;
                }
            }
            fill(ALL(tmp), 0);
            iota(ALL(to), 0);
        } else {
            F0R(p, nodeCnt + 1) {
                to[p] = nxt[to[p]][c - 'a'];
                tmp[p] += sum[to[p]];
            }
        }
    }

    ll ans = -INF;
    F0R(p, nodeCnt + 1)
        F0R(s, (1 << MAXK))
            ckmax(ans, dp[p][s] + tmp[p]);
    cout << ans << endl;
}



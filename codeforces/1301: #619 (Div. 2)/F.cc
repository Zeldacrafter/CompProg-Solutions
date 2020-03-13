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

const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};

const int MAXN = 1e3 + 5;
const int MAXK = 50;

int n, m, k;
int grid[MAXN][MAXN];
int d[MAXK][MAXN][MAXN];
vvii color;
bitset<MAXK> seenC;

void bfs(int col) {
    seenC.reset();
    seenC[col] = true;
    
    queue<ii> q;
    for(auto [r, c] : color[col]) {
        q.emplace(r, c);
        d[col][r][c] = 0;
    }

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if(!seenC[grid[r][c]]) {
            seenC[grid[r][c]] = true;
            for(auto [rr, cc] : color[grid[r][c]]) {
                if(d[col][rr][cc] != -1) continue;

                d[col][rr][cc] = d[col][r][c] + 1;
                q.emplace(rr, cc);
            }
        }

        F0R(i, 4) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
            if(d[col][rr][cc] != -1) continue;

            d[col][rr][cc] = d[col][r][c] + 1;
            q.emplace(rr, cc);
        }

    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;

    color = vvii(k);
    F0R(r, n)
        F0R(c, m) {
            cin >> grid[r][c];
            grid[r][c]--;
            color[grid[r][c]].eb(r, c);
        }

    CLR(d, -1);
    F0R(i, k)
        bfs(i);

    int q;
    cin >> q;
    while(q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        int res = abs(r1 - r2) + abs(c1 - c2);
        F0R(i, k)
            ckmin(res, d[i][r1][c1] + d[i][r2][c2] + 1);

        cout << res << endl;
    }

}


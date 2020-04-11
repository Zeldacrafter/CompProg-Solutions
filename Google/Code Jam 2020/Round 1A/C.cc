#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

int R, C;
bool inBounds(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void solve() {
    cin >> R >> C;

    vvi s(R);
    vector<vector<array<int, 4>>> adj(R);
    vector<vector<bool>> ok(R);
    F0R(i, R) {
        s[i] = vi(C);
        adj[i] = vector<array<int, 4>>(C);
        ok[i] = vector<bool>(C, true);
    }

    ll totalVal = 0;
    F0R(r, R)
        F0R(c, C) {
            cin >> s[r][c];
            totalVal += s[r][c];

            F0R(i, 4)
                if(inBounds(r + dr[i], c + dc[i]))
                    adj[r][c][i] = 1;
        }
    
    ll res = 0;
    bool change;
    do {
        change = false;
        
        res += totalVal;
        F0R(r, R) {
            F0R(c, C) {
                if(!ok[r][c])
                    continue;
                
                ll score = 0, cnt = 0;
                F0R(i, 4)
                    if(adj[r][c][i]) {
                        score += s[r + dr[i]*adj[r][c][i]][c + dc[i]*adj[r][c][i]];
                        cnt++;
                    }

                if(cnt && score > s[r][c]*cnt) {
                    ok[r][c] = false;
                    change = true;
                    totalVal -= s[r][c];
                }
            }
        }

        F0R(r, R) {
            F0R(c, C) {
                if(!ok[r][c])
                    continue;
                F0R(i, 4) {
                    if(!adj[r][c][i])
                        continue;

                    int row, col, j;
                    for(j = 0, row = r + dr[i]*adj[r][c][i],
                               col = c + dc[i]*adj[r][c][i];
                        inBounds(row, col) && !ok[row][col];
                        ++j, row += dr[i], col += dc[i]);

                    if(inBounds(row, col))
                        adj[r][c][i] += j;
                    else
                        adj[r][c][i] = 0;
                }
            }
        }
    } while(change);

    cout << res << endl;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}


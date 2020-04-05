#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pb push_back
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define CLR(a, b) memset((a), (b), sizeof((a)))

int m[100][100];
int cnt[101];
bitset<100> numInRow[100];
bitset<100> numInCol[100];

int n, k;
bool backtrack(int curr) {
    if(curr == n + 1)
        return true;

    vi rows, cols;
    F0R(r, n)
        if(!numInRow[r][curr])
            rows.pb(r);
    F0R(c, n)
        if(!numInCol[c][curr])
            cols.pb(c);

    do {
        bool ok = true;
        F0R(i, SZ(rows))
            if(m[rows[i]][cols[i]]) {
                ok = false;
                break;
            }

        if(ok) {
            F0R(i, SZ(rows))
                m[rows[i]][cols[i]] = curr;

            if(backtrack(curr + 1))
                return true;

            F0R(i, SZ(rows))
                m[rows[i]][cols[i]] = 0;
        }
    } while(next_permutation(ALL(cols)));

    return false;
}

void solve() {
    cin >> n >> k;

    if(k == n - 1 || k == n*n - 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    CLR(cnt, 0);
    CLR(m, 0);

    vi diag(n, 1);
    diag[0] = k - n + 1;
    while(true) {

        if(diag[0] <= n) {
            F0R(j, n) {
                numInRow[j].reset();
                numInCol[j].reset();
            }
            CLR(cnt, 0);

            F0R(i, n) {
                cnt[diag[i]]++;
                m[i][i] = diag[i];
                numInRow[i][diag[i]] = true;
                numInCol[i][diag[i]] = true;
            }

            int curr = 1;
            while(curr <= n && cnt[curr] == n)
                curr++;
            if(backtrack(curr)) {
                cout << "POSSIBLE\n";
                F0R(r, n)
                    F0R(c, n)
                        cout << m[r][c] << " \n"[c == n - 1];
                return;
            }
        }

        for(int i = 0;; ++i) {
            if(i == n - 1) {
                cout << "IMPOSSIBLE\n";
                return;
            }
            if(diag[i] > diag[i + 1]) {
                diag[i]--;
                diag[i + 1]++;
                break;
            }
        }
    }
}

int main() {
    int tcc;
    cin >> tcc;

    FOR (tc, 1, tcc + 1) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}



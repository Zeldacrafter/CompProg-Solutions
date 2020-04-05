#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

bitset<100> seen;
int main() {
    
    int tc;
    cin >> tc;
    FOR(tcc, 1, tc + 1) {
        cout << "Case #" << tcc << ": ";
        int n;
        cin >> n;

        vvi m(n);
        F0R(i, n) m[i] = vi(n);

        F0R(r, n)
            F0R(c, n)
                cin >> m[r][c];
    
        int trace = 0;
        F0R(i, n)
            trace += m[i][i];
            
        int rCnt = 0;
        F0R(r, n) {
            seen.reset();
            F0R(c, n) {
                if(seen[m[r][c]]) {
                    rCnt++;
                    break;
                }
                seen[m[r][c]] = true;
            }
        }

        int cCnt = 0;
        F0R(c, n) {
            seen.reset();
            F0R(r, n) {
                if(seen[m[r][c]]) {
                    cCnt++;
                    break;
                }
                seen[m[r][c]] = true;
            }
        }
        
        cout << trace << ' ' << rCnt << ' ' << cCnt << endl;
    }
}

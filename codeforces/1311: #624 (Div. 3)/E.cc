#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define ROF(a, b, c) for(auto (a) = (b); (a) >= (c); --(a))
#define R0F(a, b) ROF(a, b, 0)
#define endl '\n'

int amt[5000];
int n, d;

bool solve() {
    cin >> n >> d;

    int currSize = n * (n - 1) / 2;

    memset(amt, 0, sizeof(amt));
    F0R(i, n)
        amt[i] = 1;
    if(currSize == d) return true;

    R0F(currD, n - 1) {

        while(amt[currD]) {
            amt[currD]--;
            int lowest = currD;
            ROF(i, currD - 1, 1) {
                if(amt[i] < 2*amt[i - 1]) {
                    lowest = i;
                    if(currSize - (currD - i) == d) {
                        amt[i]++;
                        return true;
                    }
                }
            }

            if(lowest == currD)
                return false;

            currSize -= currD - lowest;
            amt[lowest]++;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        if(solve()) {
            cout << "YES\n";
            int cntTotal = 1;
            FOR(i, 1, n) {
                F0R(j, amt[i])
                    cout << 1 + cntTotal - amt[i - 1] + j/2 << ' ';
                cntTotal += amt[i];
            }
            cout << endl;
        } else {
            cout << "NO\n";
        }
    }
}

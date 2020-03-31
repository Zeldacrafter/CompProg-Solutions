#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pf push_front
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

const int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve() {
    int n, a;
    cin >> n;

    int currCol = 0;
    vi c(n);
    vi colMap(11);
    F0R(i, n) {
        cin >> a;
        F0R(j, 11) {
            if(a % primes[j])
                continue;

            if(!colMap[j])
                colMap[j] = ++currCol;
            c[i] = colMap[j];
            break;
        }
    }

    cout << currCol << endl;
    F0R(i, n)
        cout << c[i] << " \n"[i == n - 1];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


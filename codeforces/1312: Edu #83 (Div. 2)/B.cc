#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;

        vi ar(n);
        F0R(i, n) cin >> ar[i];

        sort(RALL(ar));

        F0R(i, n) cout << ar[i] << " \n"[i==n-1];
    }
}


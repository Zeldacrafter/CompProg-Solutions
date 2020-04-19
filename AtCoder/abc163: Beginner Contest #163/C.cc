#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n;
    vi amt(n);
    F0R(i, n - 1) {
        cin >> k;
        amt[k - 1]++;
    }
    F0R(i, n)
        cout << amt[i] << endl;
}



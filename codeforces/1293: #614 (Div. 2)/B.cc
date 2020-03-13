#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef vector<int> vi;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))

int main() {

    int n;
    cin >> n;

    ld sum = 0;
    FOR(i, 1, n + 1)
        sum += 1.0/i;
    cout << setprecision(10) << sum << endl;

    return 0;
}

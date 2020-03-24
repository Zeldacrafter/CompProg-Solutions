#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k, x, y;
    cin >> n >> m >> k;

    F0R(i, 2*k)
        cin >> x >> y;
    
    int cnt = m*n + m + n - 3;
    assert(cnt <= n*m*2);
    cout << cnt << endl;
    
    F0R(i, m - 1)
        cout << 'R';
    F0R(i, n - 1)
        cout << 'U';

    bool down = true;
    F0R(j, m) {
        F0R(i, n - 1)
            cout << (down ? 'D' : 'U');
        if(j != m - 1)
            cout << 'L';
        down = !down;
    }

}



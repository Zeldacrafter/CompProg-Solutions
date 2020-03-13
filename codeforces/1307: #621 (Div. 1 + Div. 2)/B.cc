#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define endl '\n'

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        int n, x, l;
        cin >> n >> x;

        int maxV = -1;
        bool found = false;
        F0R(i, n) {
            cin >> l;
            maxV = max(maxV, l);
            if(l == x)
                found = true;
        }

        int steps = x / maxV;
        if(found)
            cout << 1 << endl;
        else  if(maxV > x)
            cout << 2 << endl;
        else  if(x - steps*maxV)
            cout << steps + 1 << endl;
        else
            cout << steps << endl;
    }
}


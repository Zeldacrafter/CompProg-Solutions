#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;

        int odds = 0;
        F0R(i, n) {
            int k;
            cin >> k;
            
            if(k & 1)
                odds++;
        }

        if(odds & 1 || (odds > 0 && odds < n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

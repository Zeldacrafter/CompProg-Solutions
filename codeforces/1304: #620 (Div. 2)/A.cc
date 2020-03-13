#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        int n = y - x;
        int k = n/(a + b);
        if(n == k * (a + b))
            cout << k << endl;
        else
            cout << -1 << endl;
    }
    
}

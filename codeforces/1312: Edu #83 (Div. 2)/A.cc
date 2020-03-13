#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;

        if(n % m == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

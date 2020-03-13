#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;

        int res = 0;
        while(n >= 10) {
            res += n - n % 10;
            n = n/10 + n % 10;
        }

        cout << n + res << endl;
    }
    return 0;
}

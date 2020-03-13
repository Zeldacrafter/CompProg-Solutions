#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;

    while(tc--) {
        int A, B;
        cin >> A >> B;

        ll res = 0;
        int test = 10;
        while(test - 1 <= B) {
            res++;
            test *= 10;
        }

        res *= A;
        cout << res << endl;
    }

    return 0;
}

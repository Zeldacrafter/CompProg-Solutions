#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)

int arr[500000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        F0R(i, 2*n)
            cin >> arr[i];

        sort(arr, arr + 2*n);
        cout << abs(arr[n - 1] - arr[n]) << endl;
    }
    return 0;
}

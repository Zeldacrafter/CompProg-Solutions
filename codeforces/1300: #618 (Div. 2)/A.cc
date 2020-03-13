#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(c))
#define F0R(a, b) FOR(a, 0, b)

int arr[110];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;
        ll sum = 0;
        int cnt = 0;
        F0R(i, n) {
            cin >> arr[i];
            if(!arr[i])
                ++arr[i], ++cnt;
            sum += arr[i];
        } 
        if(!sum)
            ++cnt;

        cout << cnt << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int digitSum(int n) {
    int res = 0;
    while(n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

bool is(int n) {
    int s1 = digitSum(n);

    int s2 = 0, cnt = 0;
    for(int i = 2; i*i <= n; ++i)
        while(n % i == 0) {
            cnt++;
            s2 += digitSum(i);
            n /= i;
        }
    if(n > 1) {
        s2 += digitSum(n);
        cnt++;
    }
    if(cnt == 1)
        return false;

    return s2 == s1;
}

void solve() {
    int n;
    cin >> n;

    while(!is(++n));
    cout << n << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    F0R(i, tc)
        solve();
}


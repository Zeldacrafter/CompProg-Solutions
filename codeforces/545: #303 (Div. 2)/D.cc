#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vi a(n);
    F0R(i, n) cin >> a[i];

    sort(ALL(a));

    int currSum = 0;
    int cnt = 0;
    for(int x : a) {
        if(currSum > x) cnt++;
        else currSum += x;
    }
    cout << n - cnt << endl;
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    F0R(i, n)
        cin >> a[i];

    ll s = accumulate(ALL(a), 0);
    double amt = (double)s/(4*m);
    int cnt = 0;
    for(int i : a)
        if(i >= amt)
            cnt++;

    cout << (cnt >= m ? "Yes" : "No") << endl;
}



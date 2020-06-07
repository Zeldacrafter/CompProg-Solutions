#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vii a(n), b(n);
    F0R(i, n) { 
        cin >> a[i].fi; 
        a[i].se = i; 
    }
    F0R(i, n) { 
        cin >> b[i].fi; 
        b[i].se = i; 
    }

    sort(ALL(a));
    sort(ALL(b));

    vi offset(n);
    F0R(i, n) 
        offset[(a[i].se - b[i].se + n)%n]++;

    cout << *max_element(ALL(offset)) << endl;
}


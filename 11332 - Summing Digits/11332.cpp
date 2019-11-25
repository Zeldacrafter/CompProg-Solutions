#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))

int solve(int n) {
    if(n < 10) return n;

    int res = 0;
    while(n) {
        res += n % 10;
        n /= 10;
    }
    
    return solve(res);
}

int main() {

    int n;
    while(scanf("%d", &n), n)
        printf("%d\n", solve(n));
    return 0;
}

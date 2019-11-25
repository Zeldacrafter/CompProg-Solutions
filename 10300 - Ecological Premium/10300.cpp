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

int main() {
    int tc, f;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &f);
        int res = 0;
        while(f--) {
            int size, env;
            scanf("%d %*d %d", &size, &env);
            res += size*env;
        }
        printf("%d\n", res);
    }
}

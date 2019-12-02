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

    while(true) {
        int n;
        scanf("%d", &n);
        if(!n) break;

        int a = 0;
        int b = 0;
        int setCount = 0;
        FOR(i, 0, 31) {
            if(n & (1 << i)) {
                setCount++;
                if(setCount & 1)
                    a += 1 << i;
                else
                    b += 1 << i;
            }
        }
        printf("%d %d\n", a, b);
    }

    return 0;
}

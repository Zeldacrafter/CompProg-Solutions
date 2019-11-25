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

char buffer[1000010] = {};

int main() {

    for(int tc = 1; scanf("%1000010s", buffer) != EOF; ++tc) {

        if(buffer[0] == '\n') break;

        printf("Case %d:\n", tc);

        int tests;
        scanf("%d", &tests);
        FOR(test, 0, tests) {
            int i, j;
            scanf("%d %d", &i, &j);

            bool isSame = true;
            char bit = buffer[min(i, j)];

            FOR(k, min(i, j) + 1, max(i, j) + 1) {
                if(buffer[k] != bit) {
                    isSame = false;
                    break;
                }
            }

            if(isSame)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}

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

int fuel[12][1010];

#define INF 100000

int main() {

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int distance;
        scanf("%d", &distance);
        distance /= 100;

        // Get wind
        int wind[12][distance];
        for(int i = 10; i > 0; --i)
            FOR(j, 0, distance)
                scanf("%d", wind[i] + j);

        FOR(i, 0, distance) {
            wind[0][i] = -INF;
            wind[11][i] = -INF;
        }

        // Init dist 0
        FOR(h, 0, 12) {
            if(h == 1) {
                fuel[h][0] = 0;
            } else {
                fuel[h][0] = INF;
            }
        }

        // Build arr
        FOR(d, 1, distance + 1) {
            FOR(h, 1, 11) {
                fuel[h][d] = min(    fuel[h    ][d - 1] - wind[h    ][d - 1] + 30,
                                 min(fuel[h + 1][d - 1] - wind[h + 1][d - 1] + 20,
                                     fuel[h - 1][d - 1] - wind[h - 1][d - 1] + 60));
            }
        }

        printf("%d\n\n", fuel[1][distance]);
    }

    return 0;
}

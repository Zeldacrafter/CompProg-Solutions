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

string pages[15];
int rating[15];
char buffer[110];
int main() {
    int tc;
    scanf("%d", &tc);

    FOR(i, 1, tc + 1) {
        printf("Case #%d:\n", i);

        int maxRating = -100000;
        FOR(j, 0, 10) {
            scanf("%109s %d", buffer, rating + j);
            pages[j] = buffer;
            maxRating = max(maxRating, rating[j]);
        }

        FOR(j, 0, 10) {
            if(rating[j] == maxRating)
                printf("%s\n", pages[j].c_str());
        }
    }

    return 0;
}

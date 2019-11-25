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

int courses[110];

int main() {

    int courseAmount;
    int categoryAmount;

    while(true) {
        scanf("%d", &courseAmount);
        if(!courseAmount) break;
        scanf("%d", &categoryAmount);

        FOR(i, 0, courseAmount)
            scanf("%d", courses + i);

        bool passes = true;
        FOR(i, 0, categoryAmount) {
            int amount;
            int needed;
            scanf("%d %d", &amount, &needed);

            int has = 0;
            FOR(j, 0, amount) {
                int courseNr;
                scanf("%d", &courseNr);
                FOR(k, 0, courseAmount) {
                    if(courseNr == courses[k]) has++;
                }
            }
            if(has < needed) passes = false;
        }
        
        if(passes)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}

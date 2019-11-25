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

    int tc;
    scanf("%d", &tc);

    printf("Lumberjacks:\n");

    while(tc--) {
        int curr, next;
        scanf("%d %d", &curr, &next);
        
        int sortedCorrectly = true;
        int sortedAsc = curr > next;

        FOR(i, 0, 8) {
            curr = next;
            scanf("%d", &next);
            if( (curr > next) != sortedAsc ) 
                sortedCorrectly = false;
        }
        if(sortedCorrectly) 
            printf("Ordered\n");
        else 
            printf("Unordered\n");
    }

    return 0;
}

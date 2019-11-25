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

int deviceUsage[25];
bool on[25];

int main() {

    int devices, operations, capacity;
    for(int tc = 1; ; ++tc) {

        scanf("%d %d %d", &devices, &operations, &capacity);
        if(!devices && !operations && !capacity) break;

        printf("Sequence %d\n", tc);

        FOR(i, 1, devices + 1) {
            scanf("%d", deviceUsage + i);
            on[i] = false;
        }

        int curr = 0;
        int maxAmp = -1;
        bool blown = false;
        FOR(i, 0, operations) {
            int index;
            scanf("%d", &index);
            if(!on[index])
                curr += deviceUsage[index];
            else
                curr -= deviceUsage[index];
            on[index] = !on[index];

            if(curr > capacity) blown = true;
            maxAmp = max(maxAmp, curr);
        }

        if(blown)
            printf("Fuse was blown.\n\n");
        else 
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", maxAmp);
    }
    
    return 0;
}

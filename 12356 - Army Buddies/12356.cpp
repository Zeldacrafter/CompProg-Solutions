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

#define NONE -1
#define MAX_SIZE 100010
int l[MAX_SIZE];
int r[MAX_SIZE];

int main() {
    
    int soliderC;
    int reportC;
    while(true) {
        scanf("%d %d", &soliderC, &reportC);
        if(!soliderC && !reportC) break;

        FOR(i, 1, soliderC + 1) {
            r[i] = i + 1;
            l[i] = i - 1;
        }
        l[1] = NONE;
        r[soliderC] = NONE;

        FOR(i, 0, reportC) {
            int start, end;
            scanf("%d %d", &start, &end);

            l[r[end]] = l[start];
            r[l[start]] = r[end];

            if(l[start] == NONE) 
                printf("* ");
            else
                printf("%d ", l[start]);

            if(r[end] == NONE)
                printf("*\n");
            else
                printf("%d\n", r[end]);
        }

        printf("-\n");
    }

    return 0;
}

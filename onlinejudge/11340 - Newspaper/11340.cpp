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

int value[300];
char line[10010];

int main() {

    int tc;
    scanf("%d", &tc);
    while(tc--) {
        memset(value, 0, 300 * 4);

        int valueAmount;
        scanf(" %d", &valueAmount);
        while(valueAmount--) {
            char index;
            scanf(" %c", &index);
            scanf(" %d", value + (int)index);
        }

        int lines;
        scanf("%d\n", &lines);

        int res = 0;
        while(lines--) {
            fgets(line, 10010, stdin);
            int length = strlen(line);
            FOR(i, 0, length)
                res += value[ (int)line[i] ];
        }

        printf("%.2lf$\n", res / 100.0);
    }

    return 0;
}

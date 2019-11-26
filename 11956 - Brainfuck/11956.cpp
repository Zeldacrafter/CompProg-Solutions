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

unsigned char mem[100] = {};
char buffer[100010];

int main() {

    int tc;
    scanf("%d", &tc);

    FOR(i, 1, tc+1) {
        printf("Case %d:", i);
        scanf(" %100010s", buffer);
        int len = strlen(buffer);
        int pt = 0;
        FOR(j, 0, len) {
            switch(buffer[j]) {
                case '<':
                    --pt;
                    if(pt < 0) pt = 99;
                    break;
                case '>':
                    ++pt;
                    if(pt == 100) pt = 0;
                    break;
                case '+':
                    mem[pt]++;
                    break;
                case '-':
                    mem[pt]--;
                    break;
            }
        }

        FOR(k, 0, 100) {
            printf(" %02X", mem[k]);
        }
        printf("\n");
        memset(mem, 0, 100);
    }

    return 0;
}

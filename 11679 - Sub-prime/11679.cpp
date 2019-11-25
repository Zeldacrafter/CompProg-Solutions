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

int reserve[25];

int main() {
    int bankC, n;
    while(true) {

        scanf("%d %d", &bankC, &n);
        if(!bankC && !n) break;

        FOR(i, 1, bankC + 1) 
            scanf("%d", reserve + i);

        FOR(i, 0, n) {
            int debtor, creditor, value;
            scanf("%d %d %d", &debtor, &creditor, &value);

            reserve[debtor] -= value;
            reserve[creditor] += value;
        }
        bool notNeg = true;
        FOR(i, 1, bankC + 1) {
            if(reserve[i] < 0) {
                notNeg = false;
                break;
            }
        }

        if(notNeg) 
            printf("S\n");
        else 
            printf("N\n");
    }

    return 0;
}

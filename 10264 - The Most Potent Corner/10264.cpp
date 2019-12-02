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

int corners[100000];
int potencies[100000];

int main() {

    int n;
    while(scanf("%d", &n) != EOF) {
        memset(corners, 0, sizeof(corners));
        memset(potencies, 0, sizeof(potencies));

        FOR(i, 0, 1 << n) 
            scanf("%d", corners + i);

        FOR(i, 0, 1 << n) {
            int sum = 0;
            FOR(j, 0, n)
                sum += corners[i ^ (1 << j)];
            potencies[i] = sum;
        }

        int res = -100000;
        FOR(i, 0, 1 << n) {
            int maxVal = -100000;
            FOR(j, 0, n) 
                maxVal = max(maxVal, potencies[i ^ (1 << j)]);
            res = max(res, maxVal + potencies[i]);
        }

        printf("%d\n", res);
    }

    return 0;
}

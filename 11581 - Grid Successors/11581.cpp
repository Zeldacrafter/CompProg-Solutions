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

int matr[5][5] = {};
int start[5][5] = {};

void f() {
    char h[5][5];
    FOR(i, 1, 4) {
        FOR(j, 1, 4) {
            h[i][j] = (matr[i-1][j] + matr[i+1][j] + matr[i][j-1] + matr[i][j+1]) % 2;
        }
    }

    FOR(i, 1, 4) {
        FOR(j, 1, 4) {
            matr[i][j] = h[i][j];
        }
    }
}

bool isZero() {
    FOR(i, 1, 4)
        FOR(j, 1, 4)
            if(matr[i][j] != 0) 
                return false;
    return true;
}

int main() {

    int tc;
    scanf("%d\n\n", &tc);

    while(tc--) {
        FOR(i, 1, 4) {
            FOR(j, 1, 4) {
                char c;
                scanf(" %c", &c);
                matr[i][j] = c == '1' ? 1 : 0;
            }
        }

        int count = -1;
        while(!isZero()) {
            f();
            count++;
        }
        printf("%d\n", count);
    }

    return 0;
}

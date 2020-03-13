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

    int a, b;
    while(true) {
        scanf("%d %d", &a, &b);
        if(a == -1 && b == -1) break;

        printf("%d\n", min(min(abs(a-b), (a + 100 - b) % 100), (b + 100 - a) % 100));
    }

}

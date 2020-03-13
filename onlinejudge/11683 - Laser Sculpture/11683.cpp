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

    int width, height;
    while(true) {
        scanf("%d", &width);
        if(width == 0) break;
        scanf("%d", &height);

        int last;
        scanf("%d", &last);
        int res = width - last;
        FOR(i, 1, height) {
            int curr;
            scanf("%d", &curr);
            if(curr < last) res += last - curr;
            last = curr;
        }

        printf("%d\n", res);
    }

    return 0;
}

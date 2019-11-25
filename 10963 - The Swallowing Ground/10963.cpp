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

    while(tc--) {
        int width;
        scanf("%d", &width);

        int val = -100000;
        bool allEqual = true;
        FOR(i, 0, width) {
            int a, b;
            scanf("%d %d", &a, &b);

            if(val == -100000) val = abs(a-b);
            
            if(abs(a-b) != val) allEqual = false;
        }
        if(allEqual) printf("yes\n");
        else printf("no\n");
	if(tc) printf("\n");
    }
}

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

char line[55];

int main() {
    

    while(true) {
        scanf("%55s", line);
        int len = strlen(line);
        if(len == 1  && line[0] == '#') break;

        bool exists = next_permutation(line, line + len);
        if(exists) {
            printf("%s\n", line);
        }else {
            printf("No Successor\n");
        }
    }
    return 0;
}

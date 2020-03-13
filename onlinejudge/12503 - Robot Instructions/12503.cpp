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

int moves[110];
char buffer[50];

int main() {

    int tc;
    scanf("%d", &tc);
    
    while(tc--) {

        int n;
        scanf("%d", &n);
        fgets(buffer, sizeof(buffer), stdin);

        int pos = 0;
        FOR(i, 0, n) {
            
            fgets(buffer, sizeof(buffer), stdin);
            if(buffer[0] == 'L') {
                moves[i] = -1;
                pos -= 1;
            } else if (buffer[0] == 'R') {
                moves[i] = 1;
                pos += 1;
            } else {
                int index;
                sscanf(buffer + 8, "%d", &index);
                moves[i] = moves[index-1];
                pos += moves[i];
            }
        }
        printf("%d\n", pos);
    }
    
}

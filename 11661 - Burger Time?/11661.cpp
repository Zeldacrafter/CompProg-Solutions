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

    int length;
    
    while(true) {

        scanf("%d\n", &length);
        if (!length) break;

        string street;
        getline(cin, street);

        int minDist = length + 1;
        int rAgo = length + 1;
        int dAgo = length + 1;
        FOR(i, 0, length) {
            if(street[i] == '.') {
                rAgo++;
                dAgo++;
            } else if (street[i] == 'Z') {
                minDist = 0;
                break;
            } else if (street[i] == 'R') {
                dAgo++;
                minDist = min(minDist, dAgo);
                rAgo = 0;
            } else if (street[i] == 'D') {
                rAgo++;
                minDist = min(minDist, rAgo);
                dAgo = 0;
            }
        }

        printf("%d\n", minDist);
    }



    return 0;
}

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

#define COUNT 1000000
bitset<COUNT + 100> taken;

bool check(int start, int end) {
    for(int i = start; i < end; i++) {
        if(taken[i]) return false;
        taken[i] = true;
    }
    return true;
}

int main() {

    int oneTimeC;
    int repeatC;
    while(true) {
        scanf("%d %d", &oneTimeC, &repeatC);
        if(!oneTimeC && !repeatC) break;

        taken.reset();
        
        bool conflict = false;
        FOR(i, 0, oneTimeC) {
            int start, end;
            scanf("%d %d", &start, &end);
            if(!conflict && !check(start, end)) conflict = true;
        }
        FOR(i, 0, repeatC) {
            int start, end, interval;
            scanf("%d %d %d", &start, &end, &interval);

            while(start < COUNT && !conflict) {
                if(!check(start, end)) conflict = true;
                start += interval;
                end = min(end + interval, COUNT);
            }
        }

        if(conflict) printf("CONFLICT\n");
        else printf("NO CONFLICT\n");
        
    }

    return 0;
}

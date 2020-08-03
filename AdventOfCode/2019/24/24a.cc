#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;

bitset<(1 << 27)> seen;

bool alive[7][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0}
};
bool newAlive[7][7];

int getRating() {
    int res = 0;
    FOR(x, 1, 6)
        FOR(y, 1, 6)
            if(alive[y][x])
                res += 1 << ( (x - 1) + (y - 1)*5 );
    return res;
}

void step() {
    
    FOR(x, 1, 6) {
        FOR(y, 1, 6) {

            int adjCount = alive[y][x + 1] + alive[y][x - 1] + 
                           alive[y + 1][x] + alive[y - 1][x];

            if(alive[y][x]) {
                if(adjCount == 1)
                    newAlive[y][x] = true;
                else
                    newAlive[y][x] = false;
            } else {
                if(adjCount == 1 || adjCount == 2)
                    newAlive[y][x] = true;
                else
                    newAlive[y][x] = false;
            }
        }
    }

    FOR(x, 1, 6)
        FOR(y, 1, 6)
            alive[y][x] = newAlive[y][x];
}

int main() {

    while(true) {
        step();
        int rating = getRating();

        if(seen[rating]) {
            printf("%d\n", rating);
            break;
        } else {
            seen[rating] = true;
        }
    }

    return 0;
}
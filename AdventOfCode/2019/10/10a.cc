#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

#define WIDTH 21
#define HEIGHT 21

bool grid[HEIGHT][WIDTH];

int getSeen(int x, int y) {
    int res = 0;
    // Go through all other asteroids
    FOR(yOther, 0, WIDTH) {
        FOR(xOther, 0, HEIGHT) {
            if(grid[yOther][xOther] && (yOther != y || xOther != x)) {
                
                int relX = x - xOther;
                int relY = y - yOther;
                
                // There are only integer coordinates.
                // This means that the GCD describes the amount of 
                // equally spaced steps between (x, y) and (xOther, yOther)
                int gcdCoor = gcd(relX, relY);
                int xStep = relX/gcdCoor;
                int yStep = relY/gcdCoor;

                bool seen = true;
                FOR(step, 1, gcdCoor) {
                    // Go through all points that lay directly
                    // between (x, y) and (xOther, yOther).
                    // If one is a asteroid we cannot see (xOther, yOther).
                    if(grid[yOther + step*yStep][xOther + step*xStep]) {
                        seen = false;
                        break;
                    }
                }
                if(seen) res++;
            }
        }
    }
    return res;
}

int main() {

    char line[30];
    for(int l = 0; scanf("%30s", line) != EOF; ++l)
        FOR(i, 0, WIDTH)
            grid[l][i] = line[i] == '#';

    int maxSeen = -1;
    int bestX = -1;
    int bestY = -1;
    // Go through all asteroids and check how much they see.
    FOR(y, 0, HEIGHT) {
        FOR(x, 0, WIDTH) {
            if(grid[y][x]) {
                int seen = getSeen(x, y);
                if(maxSeen < seen) {
                    maxSeen = max(maxSeen, seen);
                    bestX = x;
                    bestY = y;
                }
            }
        }
    }

    assert(maxSeen != -1 && bestX != -1 && bestY != -1);

    printf("Seeing %d at (%d, %d)\n", maxSeen, bestX, bestY);

    return 0;
}
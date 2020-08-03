#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;

bitset<(1 << 27)> seen;

#define START_LAYER 300
bool layers[600][5][5];
bool newLayers[600][5][5];
int startLayer = START_LAYER;
int stopLayer = START_LAYER;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void step() {
    
    startLayer--;
    stopLayer++;

    FOR(l, startLayer, stopLayer + 1) {
        FOR(y, 0, 5) {
            FOR(x, 0, 5) {
                
                if(x == 2 && y == 2)
                    continue;

                int adjCount = 0;

                FOR(d, 0, 4) {
                    int newX = x + dx[d];
                    int newY = y + dy[d];
                    if(newX == 2 && newY == 2) {
                        // recurse inward
                        if(x == 3) {
                            // Right of middle
                            FOR(i, 0, 5)
                                adjCount += layers[l + 1][i][4];
                        } else if (x == 1) {
                            // Left of middle
                            FOR(i, 0, 5)
                                adjCount += layers[l + 1][i][0];
                        } else if(y == 3) {
                            // Bottom of middle
                            FOR(i, 0, 5) 
                                adjCount += layers[l + 1][4][i];
                        } else {
                            assert(y == 1);
                            // Top of middle
                            FOR(i, 0, 5) 
                                adjCount += layers[l + 1][0][i];
                        }
                    } else if(newY < 0) {
                        //Recurse outward up
                        adjCount += layers[l - 1][1][2];
                    } else if(newY >= 5) {
                        //Recurse outward down
                        adjCount += layers[l - 1][3][2];
                    } else if(newX < 0) {
                        //Recurse outward to the left
                        adjCount += layers[l - 1][2][1];
                    } else if(newX >= 5) {
                        //Recurse outward to the right
                        adjCount += layers[l - 1][2][3];
                    } else {
                        // Normal square.
                        adjCount += layers[l][newY][newX];
                    }
                }

                if(layers[l][y][x]) {
                    if(adjCount == 1)
                        newLayers[l][y][x] = true;
                    else
                        newLayers[l][y][x] = false;
                } else {
                    if(adjCount == 1 || adjCount == 2)
                        newLayers[l][y][x] = true;
                    else
                        newLayers[l][y][x] = false;
                }
            }
        }
    }

    FOR(l, startLayer, stopLayer + 1)
        FOR(x, 0, 5)
            FOR(y, 0, 5)
                layers[l][y][x] = newLayers[l][y][x];
}

ll countBugs() {
    int res = 0;

    FOR(l, startLayer, stopLayer + 1) {
        FOR(y, 0, 5) {
            FOR(x, 0, 5) {
                if(x != 2 || y != 2) {
                    res += layers[l][y][x];
                }
            }
        }
    }

    return res;
}

void printState() {
    FOR(l, startLayer, stopLayer + 1) {
        printf("Depth %d:\n", l - START_LAYER);
        FOR(y, 0, 5) {
            FOR(x, 0, 5) {
                if(x == 2 && y == 2) 
                    printf("?");
                else
                    printf("%c", layers[l][y][x] ? '#' : '.');
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {

    FOR(l, 0, 600)
        FOR(y, 0, 5)
            FOR(x, 0, 5)
                layers[l][y][x] = false;

    bool start[5][5] = {
        {1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1},
    };
    FOR(y, 0, 5)
        FOR(x, 0, 5)
            layers[START_LAYER][y][x] = start[y][x];

    FOR(stepCount, 0, 200)
        step();

    printf("%lld\n", countBugs());

    return 0;
}
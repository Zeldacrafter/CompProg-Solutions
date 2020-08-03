#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

union coord {
    int c[3];
    struct {
        int x, y, z;
    };
};

void step(coord pos[4], coord vel[4]) {

    // Gravity:
    FOR(i, 0, 4) {
        FOR(j, 0, 4) {
            FOR(k, 0, 3) {
                if( pos[i].c[k] > pos[j].c[k] ) vel[i].c[k]--;
                if( pos[i].c[k] < pos[j].c[k] ) vel[i].c[k]++;
            }
        }
    }

    // Position
    FOR(i, 0, 4)
        FOR(j, 0, 3)
            pos[i].c[j] += vel[i].c[j];
}

int main() {

    coord pos[4];
    coord vel[4] = {};
    FOR(i, 0, 4)
        scanf(" <x=%d, y=%d, z=%d>", &pos[i].x, &pos[i].y, &pos[i].z);

    // Just simulate the process
    FOR(i, 0, 1000) step(pos, vel);
    
    int energy = 0;
    FOR(i, 0, 4) {
        int pot = abs(pos[i].x) + abs(pos[i].y) + abs(pos[i].z);
        int kin = abs(vel[i].x) + abs(vel[i].y) + abs(vel[i].z);

        energy += pot * kin;
    }
    printf("Total: %d\n", energy);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
typedef long long ll;

#define PLANETS 4
#define DIMS 3

bool eq(int a[PLANETS], int b[PLANETS]) {
    FOR(i, 0, PLANETS)
        if(a[i] != b[i]) 
            return false;
    return true;
}

ll getCircleLength(int startPos[PLANETS]) {

    int currPos[PLANETS];
    memcpy(currPos, startPos, PLANETS * sizeof(startPos[0]));

    int startVel[PLANETS] = {};
    int currVel[PLANETS] = {};

    for(ll i = 1;; ++i) {
        // Update velocity
        FOR(j, 0, PLANETS) {
            FOR(k, 0, PLANETS) {
                if(currPos[j] > currPos[k]) 
                    currVel[j]--;
                else if(currPos[j] < currPos[k]) 
                    currVel[j]++;
            }
        }

        // Update position
        FOR(j, 0, PLANETS)
            currPos[j] += currVel[j];

        if(eq(startPos, currPos) && eq(startVel, currVel))
            return i;
    }

    assert(false); // How did we get here?
    return -1;
}

int main() {

    // Key observation: All directional components (x, y, z) are independent.
    // Search for cycles in every component individually.
    // The full cycle of all components is the lcm of the small cycles.

    // Key observation 2: A cycle can be detected by looking at when the 
    // start state repeats:
    // The start state needs to be part of the cycle because 
    // for any given state there can only be one previous state.

    int input[DIMS][PLANETS];
    FOR(i, 0, PLANETS)
        scanf(" <x=%d, y=%d, z=%d>", &input[0][i], &input[1][i], &input[2][i]);

    // Go through all components and update the total circle length.
    ll totalCircle = 1L;
    FOR(c, 0, DIMS)
        totalCircle = lcm(totalCircle, getCircleLength(input[c]));

    printf("%lld\n", totalCircle);
    return 0;
}
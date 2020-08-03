#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

#define WIDTH 21
#define HEIGHT 21
#define EPS 1e-4

#define ORIGIN_X 11
#define ORIGIN_Y 13

typedef complex<int> ci;

ci orig(ORIGIN_X, ORIGIN_Y);
bool grid[HEIGHT][WIDTH];

double angle(ci a, ci b, ci o) {
    // Returns the angle between a and b with the origin o.

    // We need to convert our complex numbers to doubles
    // so that arg() works correctly.
    // Alternatively we could also use atan2(imag(), real())
    complex<double> ao(real(a - o), imag(a - o));
    complex<double> bo(real(b - o), imag(b - o));

    double angle = arg(bo) - arg(ao);

    // Account for the fact that arg() returns an angle in the interval [-PI:PI].
    // Shift the part from [-PI:0] to [PI:2*PI] to make calculations easier.
    if(angle < 0)
        angle += 2*M_PI;
    return angle;
}

ci getNext(ci prev) {
    double minAngle = 1000.0;
    ci best(-1, -1);
    // Try all asteroids
    FOR(tryY, 0, HEIGHT) {
        FOR(tryX, 0, WIDTH) {
            if(grid[tryY][tryX]) {
                ci tryPt(tryX, tryY);

                double a = angle(prev, tryPt, orig);
                if(abs(a) < EPS) continue; // Pt is on same line.

                int bestDist = abs(best - orig);
                int tryDist = abs(tryPt - orig);

                // Check if we found a asteroid with an
                // lower angle or the same angle and less distance
                if((a < minAngle || (abs(minAngle - a) < EPS && bestDist > tryDist))) {
                    best = tryPt;
                    minAngle = a;
                }

            }
        }
    }
    assert(minAngle != 1000.0);
    return best;
}

int main() {
    char line[30];
    for(int l = 0; scanf("%30s", line) != EOF; ++l)
        FOR(i, 0, WIDTH) 
            grid[l][i] = line[i] == '#';

    // Mark our asteroid as not-existing
    // because we do not want to hit it.
    grid[ORIGIN_Y][ORIGIN_X] = false;

    // Find start straight up from ORIGIN
    ci curr(-1, -1);
    FOR(dy, 1, HEIGHT) {
        if(ORIGIN_Y - dy < 0) break;

        if(grid[ORIGIN_Y - dy][ORIGIN_X]) {
            curr = ci(ORIGIN_X, ORIGIN_Y - dy);
            break;
        }
    }

    // Assume that a starting point exists.
    assert(curr != ci(-1, -1));

    // Kill asteroid and move to next repeatedly
    FOR(i, 1, 200) {
        grid[imag(curr)][real(curr)] = false;
        curr = getNext(curr);
    }

    printf("%d\n", real(curr) * 100 + imag(curr));
    return 0;
}
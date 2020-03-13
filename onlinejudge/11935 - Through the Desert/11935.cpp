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

char buffer[100];

int main() {

    while(1) {
        int dist;
        int consumption;
        scanf("%d Fuel consumption %d\n", &dist, &consumption);

        if(!consumption && !dist) break;

        int maxFuelNeeded = -1;

        int leakAmount = 0;
        int fuelNeeded = 0;
        int lastDist = 0;
        bool end = false;
        while(!end) {

            scanf("%d %100[^\n]", &dist, buffer);

            int diff = dist - lastDist;
            fuelNeeded += diff * leakAmount * 100;  // Fuel needed by leaks
            fuelNeeded += diff * consumption;       // Fuel needed in general
            lastDist = dist;
            switch(buffer[0]) {

                case 'G':
                    // Gas Station or Goal
                    maxFuelNeeded = max(maxFuelNeeded, fuelNeeded);
                    fuelNeeded = 0;
                    if(buffer[1] == 'o')
                        end = true;
                    break;
                case 'L':
                    // Leak
                    leakAmount++;
                    break;
                case 'M':
                    // Mechanic
                    leakAmount = 0;
                    break;
                case 'F':
                    // Fuel consumption change
                    sscanf(buffer, "Fuel consumption %d", &consumption);
                    break;
                default:
                    printf("Unknown command: %s\n", buffer);
                    assert(false);
                    break;
            }
        }
        printf("%.3lf\n", maxFuelNeeded/100.0f);
    }

    return 0;
}

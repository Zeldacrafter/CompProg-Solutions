#include <bits/stdc++.h>
using namespace std;

int main() {

    int dist;
    int sum = 0;
    while(scanf(" %d", &dist) != EOF) {

        int fuel = dist;
        while(true) {
            fuel = fuel/3 - 2;
            if(fuel <= 0) break;
            sum += fuel;
        }
    }

    printf("%d\n", sum);

    return 0;
}
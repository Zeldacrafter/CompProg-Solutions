#include <bits/stdc++.h>
using namespace std;

int main() {

    int dist;
    int sum = 0;
    while(scanf(" %d", &dist) != EOF) {
        sum += dist/3 - 2;
    }

    printf("%d\n", sum);

    return 0;
}
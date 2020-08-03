#include <bits/stdc++.h>
using namespace std;

#define WIDTH 25
#define HEIGHT 6
#define LAYER_COUNT 100

int main() {

    int nrCount[LAYER_COUNT][10];
    int digitNr = 0;
    int layerNr = 0;

    char digit;
    while(scanf(" %c", &digit) != EOF) {
        nrCount[layerNr][digit - '0']++;

        digitNr++;
        if(digitNr == WIDTH * HEIGHT) {
            digitNr = 0; // Next layer
            layerNr++;
        }
    }

    int fewestZeroCount = WIDTH*HEIGHT + 1;
    int res = -1;
    for(int l = 0; l < layerNr; ++l) {
        if(nrCount[l][0] < fewestZeroCount) {
            fewestZeroCount = nrCount[l][0];
            res = nrCount[l][1] * nrCount[l][2];
        }
    }

    printf("%d\n", res);
    return 0;
}
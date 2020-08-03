#include <bits/stdc++.h>
using namespace std;

#define WIDTH 25
#define HEIGHT 6
#define LAYER_COUNT 100

int main() {

    int shownDigit[WIDTH][HEIGHT];
    memset(shownDigit, -1, sizeof(shownDigit[0][0]) * WIDTH * HEIGHT);

    int digitNr = 0;
    int layerNr = 0;

    char digit;
    while(scanf(" %c", &digit) != EOF) {
        // Since the first layer is sent first we can simply override
        // every pixel with the first occurance of a non-transperant input
        // for that coordinate.
        if(digit != '2' && shownDigit[digitNr % WIDTH][digitNr / WIDTH] == -1)
            shownDigit[digitNr % WIDTH][digitNr / WIDTH] = digit - '0';

        digitNr++;
        if(digitNr == WIDTH * HEIGHT) {
            digitNr = 0; // Next layer
            layerNr++;
        }
    }

    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            assert(shownDigit[x][y] != -1); // All pixels are filled.
            if(!shownDigit[x][y])
                printf("⬛");
            else
                printf("⬜"); 
        }
        printf("\n");
    }
        
    return 0;
}
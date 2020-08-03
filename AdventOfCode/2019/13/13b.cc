#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
typedef long long ll;
typedef pair<int, int> ii;

#define NONE -1000

#define EMPTY 0
#define WALL 1
#define BLOCK 2
#define PADDLE 3
#define BALL 4

#define SIZE 50
int tiles[SIZE][SIZE];
int score = 0;

void printField() {
    this_thread::sleep_for(chrono::milliseconds(10));
    system("clear");
    printf("SCORE: %d\n\n", score);
    FOR(y, 0, 25) {
        FOR(x, 0, SIZE) {
            switch(tiles[x][y]) {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("▓");
                    break;
                case BLOCK:
                    printf("░");
                    break;
                case PADDLE:
                    printf("≡");
                    break;
                case BALL:
                    printf("☉");
                    break;
                default:
                    printf("Returning (%d, %d): %d\n", x, y, tiles[x][y]);
                    return;
                    assert(false);
            }
        }
        printf("\n");
    }
}

int sgn(int n) {
    return (0 < n) - (n < 0);
}

int main() {

    vector<ll> memory;
    ll opcode;
    for(int c = scanf(" %lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);

    // As described in assignment.
    memory[0] = 2;

    int ballX;
    int padX;
    IntCodeInterpreter(memory,
        [&ballX, &padX]() {
            //printField();

            return sgn(ballX - padX);
        },
        [&ballX, &padX](ll outp) {
            static int x = NONE;
            static int y = NONE;

            if(x == NONE) {
                x = outp;
            } else if(y == NONE) {
                y = outp;
            } else {
                
                if(x == -1 && y == 0) {
                    score = outp;
                } else {
                    tiles[x][y] = outp;
                    // Track where the pad/ball is
                    if(outp == BALL)
                        ballX = x;
                    else if (outp == PADDLE)
                        padX = x;
                }
                
                x = NONE;
                y = NONE;
            }
        }, false)
        .run();

    printf("%d\n", score);
}

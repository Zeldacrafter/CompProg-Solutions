#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
typedef long long ll;
typedef pair<int, int> ii;

#define NONE -1

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main() {

    vector<ll> memory;
    ll opcode;
    for(int c = scanf(" %lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);

    bool painted[1000][1000] = {};
    int robotX = 500;
    int robotY = 500;

    // Robot start on black tile
    painted[robotX][robotY] = 1;

    // Keep track of how far the robot went in either direction
    ii boundX(1000, 0);
    ii boundY(1000, 0);

    IntCodeInterpreter (
        memory,
        [&painted, &robotX, &robotY]() {
            return painted[robotX][robotY];
        },
        [&painted, &robotX, &robotY, &boundX, &boundY](ll outp) {
            static int color = NONE;
            static int dir = UP;
            if(color == NONE)
                color = outp; // First output
            else {
                // Got second output
                assert(color == 0 || color == 1);
                painted[robotX][robotY] = color;

                assert(outp == 0 || outp == 1);
                dir = (dir + (!outp ? (-1 + 4) : 1) ) % 4;
                robotX += dx[dir];
                robotY += dy[dir];
                
                boundX = ii(min(boundX.first, robotX), max(boundX.second, robotX));
                boundY = ii(min(boundY.first, robotY), max(boundY.second, robotY));

                color = NONE;
            }

        },
        false)
        .run();

    // Show what the robot painted
    FOR(y, boundY.first, boundY.second + 1) {
        FOR(x, boundX.first, boundX.second + 1) {
            if(painted[x][y])
                printf("⬜");
            else
                printf("⬛");
        }
        printf("\n");
    }

    return 0;
}
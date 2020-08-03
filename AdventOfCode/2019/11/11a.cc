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
int dy[] = {1, 0, -1, 0};

int main() {

    vector<ll> memory;
    ll opcode;
    for(int c = scanf(" %lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);

    bool painted[1000][1000] = {};
    int robotX = 500;
    int robotY = 500;
    set<ii> visited;

    IntCodeInterpreter (
        memory,
        [&painted, &robotX, &robotY]() {
            return painted[robotX][robotY];
        },
        [&painted, &robotX, &robotY, &visited](ll outp) {
            static int color = NONE;
            static int dir = UP;
            if(color == NONE)
                color = outp; // First output
            else {
                // Got second output
                assert(color == 0 || color == 1);
                visited.insert(ii(robotX, robotY));
                painted[robotX][robotY] = color;

                assert(outp == 0 || outp == 1);
                dir = (dir + (!outp ? (-1 + 4) : 1) ) % 4;
                robotX += dx[dir];
                robotY += dy[dir];
                
                color = NONE;
            }

        },
        false)
        .run();

    printf("Amount painted: %ld", visited.size());

    return 0;
}
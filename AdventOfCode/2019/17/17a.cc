#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
typedef long long ll;

int main() {
    vector<ll> memory;

    ll opcode;
    for(int c = scanf(" %lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);

    char grid[100][100];
    int maxX = 0;
    int maxY = 0;
    IntCodeInterpreter(memory,
        []() { assert(false); return -1; }, // No input needed.
        [&grid, &maxX, &maxY](ll outp) {
            static int x = 0;
            static int y = 0;

            if(outp == '\n') {
                x = 0;
                ++y;
            } else {
                grid[x][y] = (char)outp;
                ++x;
            }
            maxX = max(x, maxX);
            maxY = max(y, maxY);
        },
        false
        ).run();


    int sum = 0;
    FOR(y, 0, maxY)
        FOR(x, 0, maxX)
            // Check if all adj are scaffolding
            if(   grid[x][y] == '#'
               && grid[x-1][y] == '#'
               && grid[x+1][y] == '#'
               && grid[x][y-1] == '#'
               && grid[x][y+1] == '#')
                sum += x * y;
    printf("%d\n", sum);

    return 0;
}
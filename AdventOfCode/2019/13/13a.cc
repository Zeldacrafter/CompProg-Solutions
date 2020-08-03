#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
typedef long long ll;

#define NONE -1

#define EMPTY 0
#define WALL 1
#define BLOCK 2
#define PADDLE 3
#define BALL 4

int main() {
    vector<ll> memory;
    ll opcode;
    for(int c = scanf(" %lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);

    int count = 0;
    IntCodeInterpreter(memory,
        []() {
            return -1;
        },
        [&count](ll outp) {
            static int x = NONE;
            static int y = NONE;

            if(x == NONE) 
                x = outp;
            else if(y == NONE) 
                y = outp;
            else {
                if(outp == BLOCK) count++;
                x = NONE;
                y = NONE;
            }
        }, false)
        .run();

    printf("%d\n", count);
}

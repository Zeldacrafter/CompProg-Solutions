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

    IntCodeInterpreter(memory,
        []() { return 1; },
        [](ll outp) { printf("Part 1: %lld\n", outp); },
        false)
            .run();

    IntCodeInterpreter(memory,
        []() { return 2; },
        [](ll outp) { printf("Part 2: %lld\n", outp); },
        false)
            .run();

    return 0;
}
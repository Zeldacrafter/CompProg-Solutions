#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

typedef long long ll;

#define WANTED 19690720LL

int main() {

    vector<ll> memory;
    ll opcode;
    for(int c = scanf("%lld", &opcode); c != EOF; c = scanf(",%lld", &opcode))
        memory.push_back(opcode);
    
    IntCodeInterpreter vm(
        memory,
        []() { assert(false); return -1; }, // Not used.
        [](ll outp) { assert(false); },     // Not used.
        false);

    for(ll noun = 0; noun < 100; noun++) {
        for(ll verb = 0; verb < 100; verb++) {
            memory[1] = noun;
            memory[2] = verb;
            
            vm.reset(memory);
            vm.run();

            if(vm.modifyMemory(0) == WANTED) {
                printf("%lld", 100*noun + verb);
                exit(0);
            }
        }
    }

    printf("Could not find wanted value!\n");
    return -1;
}
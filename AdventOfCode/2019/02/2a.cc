#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

typedef long long ll;

int main() {

    vector<ll> memory;
    ll opcode;
    for(int c = scanf("%lld", &opcode); c != EOF; c = scanf(",%lld", &opcode))
        memory.push_back(opcode);
    
    memory[1] = 12;
    memory[2] = 2;
    
    IntCodeInterpreter vm(
        memory,
        []() { assert(false); return -1; }, // Not used.
        [](ll outp) { assert(false); },     // Not used.
        false);

    vm.run();
    printf("%lld\n", vm.modifyMemory(0));
    return 0;
}
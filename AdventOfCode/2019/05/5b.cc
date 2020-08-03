#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

typedef long long ll;

int main() {
    

    vector<ll> memory;
    ll opcode;
    for(int c = scanf("%lld", &opcode); c != EOF; c = scanf(",%lld", &opcode))
        memory.push_back(opcode);
    
    IntCodeInterpreter interp (
        memory,
        []() { return 5; },
        [](ll out) { printf("%lld\n", out); },
        false);
    interp.run();

    return 0;
}
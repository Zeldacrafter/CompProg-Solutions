#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;

int main() {

    ll opcode;
    vector<ll> memory;
    for(int c = scanf("%lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);
    
    int maxVal = 0;
    int phaseSequence[5] = {0,1,2,3,4};
    do { // Cycle through all permutations

        int output = 0; // Initial input for first VM is 0
        FOR(i, 0, 5) {
            // Initilize input
            queue<ll> inQ({phaseSequence[i], output});
            bool hasOutput = false;

            IntCodeInterpreter vm( memory,
                [&inQ]() {
                    // Get next input
                    ll inp = inQ.front();
                    inQ.pop();
                    return inp;
                },
                [&output, &hasOutput](ll out) {
                    // Signal we got output and can
                    // proceed with next VM.
                    output = out; 
                    hasOutput = true; 
                } );
            
            // Run until we got output.
            while(!hasOutput)
                vm.eval();
        }

        // Check if our value is a new best
        maxVal = max(maxVal, output);

    } while(next_permutation(phaseSequence, phaseSequence + 5));

    printf("%d\n", maxVal);
    return 0;
}
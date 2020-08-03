#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;

int main() {

    vector<ll> memory;
    ll opcode;
    for(int c = scanf("%lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);

    ll output;
    bool hasOutput;
    queue<ll> inQ[5];
    vector<IntCodeInterpreter> vms;

    // Init vms
    FOR(i, 0, 5) {
        vms.push_back(IntCodeInterpreter(
            memory,
            [&inQ, i]() {
                assert(!inQ[i].empty());

                // Read next input from queue
                ll res = inQ[i].front();
                inQ[i].pop();
                return res;
            },
            [&inQ, i, &output, &hasOutput](ll outp) {
                
                // Push input into next VM in queue
                inQ[(i + 1) % 5].push(outp);
                if(i == 4) // Last VM might generate final res.
                    output = outp;
                hasOutput = true; // Signal we want to run the next VM
            },
            false
        ));
    }

    ll phaseSequence[5] = {5,6,7,8,9};
    ll maxVal = -1000;
    do { // Cycle through all permutations

        // Reset VMS + Init input
        FOR(i, 0, 5) {
            while(!inQ[i].empty()) 
                inQ[i].pop();
            inQ[i].push(phaseSequence[i]);
            vms[i].reset(memory);
        }
        inQ[0].push(0);

        // Run VMS
        bool halted = false;
        for(int i = 0; !halted; i = (i + 1) % 5) {
            hasOutput = false;
            while(!halted && !hasOutput) 
                halted = !vms[i].eval();
        }

        // Check if we got a better value
        maxVal = max(maxVal, output);
    } while(next_permutation(phaseSequence, phaseSequence + 5));

    printf("%lld\n", maxVal);
    return 0;
}
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

    pair<ll, ll> NAT(-1, -1);
    bitset<50> idle;
    queue<ll> inputQ[50];
    vector<ll> output[50];

    vector<IntCodeInterpreter> vms;
    FOR(id, 0, 50) {
        inputQ[id].push(id);

        vms.emplace_back(memory,
            [&inputQ, id, &idle]() {
                if(inputQ[id].empty()) {
                    idle[id] = true;           // No input. We are idle
                    
                    return -1LL;
                } else {
                    idle[id] = false;          // Found input. We are not idle
                    
                    ll res = inputQ[id].front();
                    inputQ[id].pop();
                    return res;
                }
            },
            [&inputQ, &output, id, &idle, &NAT](ll out) {
                idle[id] = false;              // Got output. We are not idle.

                output[id].push_back(out);

                if(output[id].size() == 3) {
                    ll addr = output[id][0];
                    ll x = output[id][1];
                    ll y = output[id][2];
                    
                    if(addr == 255) {
                        printf("New NAT: (%lld, %lld)\n", x, y);
                        NAT = pair<ll, ll>(x, y);
                    } else {
                        idle[addr] = false;
                        inputQ[addr].push(x);
                        inputQ[addr].push(y);
                    }
                    output[id].clear();
                }
            });
    }

    ll lastNatY = -1000;
    int ticksIdle = 0;
    while(true) {

        if(ticksIdle >= 5000) {
            assert(NAT.first != -1 || NAT.second != -1); // Nat exists

            inputQ[0].push(NAT.first);
            inputQ[0].push(NAT.second);
            
            printf("Sending NAT (%lld, %lld)\n", NAT.first, NAT.second);
            if(lastNatY == NAT.second) {
                printf("Result: %lld\n", lastNatY);
                exit(0);
            }
            lastNatY = NAT.second;
            ticksIdle = 0;
            FOR(i, 0, 50) idle[i] = false;
        }

        FOR(i, 0, 50)
            vms[i].eval();

        if(idle.all()) ticksIdle++;
        else ticksIdle = 0;
    }

    return 0;
}
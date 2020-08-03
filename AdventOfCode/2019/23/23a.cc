#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;
typedef long long ll;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

int main() {

    vector<ll> memory;

    ll opcode;
    for(int c = scanf(" %lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);

    queue<ll> inputQ[50];
    vector<ll> output[50];
    vector<IntCodeInterpreter> computers;
    FOR(i, 0, 50) {
        inputQ[i].push(i);

        computers.emplace_back(
            memory, 
            [&inputQ, i]() {
                if(inputQ[i].empty()) {
                    return -1LL;
                } else {
                    ll res = inputQ[i].front();
                    inputQ[i].pop();
                    return res;
                }
            },
            [&inputQ, &output, i](ll out) {
                output[i].push_back(out);

                if(output[i].size() == 3) {
                    ll addr = output[i][0];
                    ll x = output[i][1];
                    ll y = output[i][2];
                    if(addr == 255) {
                        printf("(%lld, %lld) send from %d to %lld\n", x, y, i, addr);
                        exit(0);
                    } else {
                        inputQ[addr].push(x);
                        inputQ[addr].push(y);
                        output[i].clear();
                    }

                }
            });
    }

    for(int i = 0;; i = (i + 1) % 50)
        computers[i].eval();

    return 0;
}
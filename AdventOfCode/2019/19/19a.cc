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

    int count = 0;
    queue<ll> q;
    IntCodeInterpreter vm(memory,
        [&q]() {
            ll res = q.front();
            q.pop();
            return res;
        },
        [&count](ll outp) {
            if(outp) count++;
        },
        false);

    FOR(x, 0, 50) {
        FOR(y, 0, 50) {
            q.push(x);
            q.push(y);
        
            vm.reset(memory);
            vm.run();
        }
    }
    printf("%d\n", count);

    return 0;
}
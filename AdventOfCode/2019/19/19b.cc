#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
typedef long long ll;

bool testCoord(const vector<ll> &memory, int x, int y) {
    queue<ll> q;
    bool res;

    static IntCodeInterpreter vm(
        memory,
        [&q]() {
            ll res = q.front();
            q.pop();
            return res;
        },
        [&res](ll outp) { res = outp; },
        false);

    q.push(x);
    q.push(y);
    vm.reset(memory);
    vm.run();

    return res;
}

int main() {

    vector<ll> memory;
    ll opcode;
    for(int c = scanf(" %lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        memory.push_back(opcode);

    int xMin = 0;
    FOR(y, 0, 10000) { // Upper limit 10000 because the result is (10000*y + x)
        bool found = false;
        FOR(x, xMin, 10000) {

            if(testCoord(memory, x, y)) {

                // To test if there is a 100*100 square we only need to 
                // test if the block 99 down and 99 right is filled.
                if(testCoord(memory, x + 99, y) && testCoord(memory, x, y + 99)) {
                    printf("%d\n", x*10000 + y);
                    return 0;
                }

                if(!found) {
                    xMin = x;
                    found = true;
                }
            } else {
                // if we previously checked a square that was hit by the ray
                // and now find one that is not we know that we 
                // reached the end of this row.
                if(found) break;
            }
        }
    }

    return 0;
}
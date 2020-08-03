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

    // See assignmnet.
    memory[0] = 2;

    char inputArr[] = "A,C,A,C,A,B,A,B,C,B\n" // Instructions
                      "R,6,L,10,R,10,R,10\n"  // A
                      "R,6,L,12,L,10\n"       // B
                      "L,10,L,12,R,10\n"      // C
                      "n\n";                  // Video feed: y/n

    queue<ll> input;
    for(char c : inputArr)
        input.push(c);

    IntCodeInterpreter(memory,
        [&input](){
            assert(!input.empty());

            ll res = input.front();
            input.pop();
            return res;
        },
        [](ll outp){
            if(outp < 256)
                printf("%c", (char)outp);
            else
                printf("%lld\n", outp);
        },
        true).run();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))


#define POS 0
#define IMM 1
#define REL 2

typedef long long ll;

#define HALT -1

struct outp {
    int ip;
    int relBase;
    vector<ll> out;
};

ll get(unordered_map<int, ll> &mem, int key) {
    if(mem.find(key) != mem.end())
        return mem[key];
    else 
        return 0;
}

void setArgs(unordered_map<int, ll> &mem, int iPt, int n, int modes[], bool hasOutput, int relBase, ll *res) {

    // Index 0 is invalid so that parameter nr n is corresponding to index n.
    res[0] = -1;
    for(int i = 1; i < n + 1; ++i) {
        int pos = iPt + i;
        switch(modes[i-1]) {
            case POS:
                if(i == n && hasOutput) {
                    res[i] = get(mem, pos);
                } else {
                    res[i] = get(mem, get(mem, pos));
                }
                break;
            case IMM:
                res[i] = get(mem, pos);
                break;
            case REL:
                if(i == n && hasOutput) {
                    res[i] = get(mem, pos) + relBase;
                } else {
                    res[i] = get(mem, get(mem, pos) + relBase);
                }
                break;
        }
    }
}

outp run(unordered_map<int, ll> &memory, queue<char> input, int ip, int relBase) {
    //printf("Run: %s\n", dStr[input].c_str());
    vector<ll> output;

    while(true) {
        
        int opcode = memory[ip] % 100;
        int modes[3];
        for(int m = 0; m < 3; ++m)
            modes[m] = ((memory[ip] / (int)pow(10, m + 2)) % 10);
        
        ll args[5];
        switch (opcode) {
        case 1:
            setArgs(memory, ip, 3, modes, true, relBase, args);
            
            memory[args[3]] = args[1] + args[2];
            ip += 4;
            break;
        case 2:
            setArgs(memory, ip, 3, modes, true, relBase, args);
            
            memory[args[3]] = args[1] * args[2];
            ip += 4;
            break;
        case 3:
            setArgs(memory, ip, 1, modes, true, relBase, args);
            assert(input.size() > 0);
            memory[args[1]] = input.front();
            input.pop();
            ip += 2;
            break;
        case 4:
            setArgs(memory, ip, 1, modes, false, relBase, args);
            ip += 2;
            output.push_back(args[1]);
            break;
        case 5:
            setArgs(memory, ip, 2, modes, false, relBase, args);
            
            if(args[1])
                ip = args[2];
            else ip += 3;
            break;
        case 6:
            setArgs(memory, ip, 2, modes, false, relBase, args);
            
            if(!args[1])
                ip = args[2];
            else ip += 3;
            break;
        case 7:
            setArgs(memory, ip, 3, modes, true, relBase, args);
            
            memory[args[3]] = args[1] < args[2] ? 1 : 0;
            ip += 4;
            break;
        case 8:
            setArgs(memory, ip, 3, modes, true, relBase, args);
            
            memory[args[3]] = args[1] == args[2] ? 1 : 0;
            ip += 4;
            break;
        case 9:
            setArgs(memory, ip, 1, modes, false, relBase, args);
            relBase += args[1];
            ip += 2;
            break;
        case 99:
            return {HALT, HALT, output};
        default:
            printf("Error: OpCode %lld read with IP %d\n", memory[ip], ip);
            assert(false);
        }
    }
}


int main() {

    unordered_map<int, ll> memory;

    ll opcode;
    for(int c = scanf(" %lld", &opcode), i = 0; 
            c != EOF; 
            c = scanf(" ,%lld", &opcode), ++i) {
        memory[i] = opcode;
    }

    string inputStringA = 
         "NOT C J\n"
         "NOT B T\n"
         "OR T J\n"
         "NOT A T\n"
         "OR T J\n"
         "AND D J\n"
         "WALK\n";

    string inputStringB = 
         "NOT A T\n"
         "NOT B J\n"
         "OR T J\n"
         "NOT C T\n"
         "OR T J\n"

         "AND D J\n"

         "NOT F T\n"
         "NOT T T\n"
         ""
         "OR I T\n"
         "AND E T\n"
         "OR H T\n"
         "AND T J\n"

         "RUN\n";

    queue<char> input;
    FOR(i, 0, inputStringB.size()) {
        input.push(inputStringB[i]);
    }

    outp output = run(memory, input, 0, 0);
    FOR(i, 0, output.out.size()) {
        if(output.out[i] == '\n') printf("\n");
        else printf("%c", output.out[i]);
    }
    return 0;
}
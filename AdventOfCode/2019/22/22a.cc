#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;

char operation[100];

int main() {

    int pos = 2019;
    int cards = 10007;

    while(scanf(" %100[^\n]", operation) != EOF) {
        if(operation[0] == 'd') {
            if(operation[5] == 'w') {
                // Deal with increment N
                int increment;
                sscanf(operation, "deal with increment %d", &increment);

                pos = (pos*(ll)increment) % cards;
            } else {
                assert(operation[5] == 'i');

                // Deal into new stack
                pos = cards - pos - 1;
            }
        } else {
            assert(operation[0] == 'c');
            
            // Cut N
            int cutAmount;
            sscanf(operation, "cut %d", &cutAmount);
            pos = (pos - cutAmount + cards) % cards;
        }

    }

    printf("%d\n", pos);

    return 0;
}
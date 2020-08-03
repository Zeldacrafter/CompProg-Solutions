#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;

char operation[100];

#define INC 0
#define CUT 1
#define STACK 2

#define ITER_AMOUNT 101741582076661LL
#define CARDS 119315717514047LL

struct op {
    int id;
    ll amount;
};

ll modpow(ll b, ll e, ll m) {
    if(e == 0) 
        return 1;

    if(e % 2 == 0)
        return modpow((b*b) % m, e / 2, m);
    
    return (b * modpow(b, e - 1, m)) % m;
}

ll modinv(ll a, ll m) {
    //Because m is prime
    return modpow(a, m - 2, m);
}

vector<op> ops;

ll next(ll pos) {
    for(op curr : ops) {
        switch(curr.id) {
            case CUT:
                pos = (pos + curr.amount + CARDS) % CARDS;
                break;
            case STACK:
                pos = CARDS - 1 - pos;
                break;
            case INC:
                //FIXME: Overflow: 
                pos = (modinv(curr.amount, CARDS) * pos) % CARDS;
                assert(pos >= 0);
                break;
            default:
                assert(false);
        }
    }

    return pos;
}
int main() {

    while(scanf(" %100[^\n]", operation) != EOF) {
        if(operation[0] == 'd') {
            if(operation[5] == 'w') {
                int increment;
                sscanf(operation, "deal with increment %d", &increment);
                ops.push_back({INC, increment});
            } else {
                assert(operation[5] == 'i');
                ops.push_back({STACK, -100000});
            }
        } else {
            assert(operation[0] == 'c');
            int cutAmount;
            sscanf(operation, "cut %d", &cutAmount);
            ops.push_back({CUT, cutAmount});
        }
    }
    reverse(ops.begin(), ops.end());

    // p = a * p_old + b
    ll pos = 2020;
    
    ll X = next(pos);
    ll Y = next(X);
    ll Z = next(Y);

    printf("%lld, %lld, %lld", X, Y, Z);

    return 0;
}
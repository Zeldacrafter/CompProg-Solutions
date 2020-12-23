#include "../template.cc"

typedef list<int>::const_iterator IT;

const int ITERS = 10000000;
const int MX = 1000000;

list<int> a; 
array<IT, MX + 1> toIt;

IT adv(IT it, int n = 1) {
    F0R(i, n) {
        it = next(it);
        if(it == a.end())
            it = a.begin();
    }
    return it;
}

void solve() {
    string s = getInp()[0];

    for(char c : s) {
        a.pb(c - '0');
        toIt[a.back()] = prev(a.end());
    }
    while(SZ(a) < MX) {
        a.pb(SZ(a) + 1);
        toIt[a.back()] = prev(a.end());
    }

    IT currIt = a.begin();
    F0R(i, ITERS) {

        int toInsert;
        for(toInsert = *currIt - 1; ; --toInsert) {
            if(!toInsert) toInsert = MX;
            bool ok = true;
            F0R(k, 3) ok &= toInsert != *adv(currIt, k + 1);
            if(ok) break;
        }

        F0R(j, 3) {
            IT now = adv(currIt, 3 - j);
            a.splice(adv(toIt[toInsert]), a, now, next(now));
        }

        currIt = adv(currIt);
    }

    IT one = find(ALL(a), 1);
    cout << (ll)*adv(one) * *adv(one, 2) << endl;
}


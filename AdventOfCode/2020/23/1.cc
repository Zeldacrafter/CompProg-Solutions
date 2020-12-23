#include "../template.cc"

typedef list<int>::const_iterator IT;

const int ITERS = 100;
const int MX = 9;

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

    IT currIt = a.begin();
    F0R(_, ITERS) {

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

    a.splice(a.end(), a, a.begin(), find(ALL(a), 1));
    a.pop_front();
    cout << pp(a, "") << endl;
}


#include "../template.cc"

const int DIV = 20201227;
const int SUBNUM = 7;

void solve() {
    ll pub1, pub2;
    cin >> pub1 >> pub2;

    ll i = 0;
    for(ll curr = 1; curr != pub1; i++)
        curr = (curr * SUBNUM) % DIV;

    ll curr = 1;
    F0R(_, i)
        curr = (curr * pub2) % DIV;
    cout << curr << endl;
}


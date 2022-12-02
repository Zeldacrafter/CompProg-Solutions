#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        char a, b; cin >> a >> b;

        a -= 'A';
        b -= 'X';

        res += b + 1;
        if(a == b)
            res += 3;
        else if((a + 1) % 3 == b)
            res += 6;
    });


    cout << res << endl;
}


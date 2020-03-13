#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))

bitset<100010> lava[2];

int main() {

    int n, q;
    cin >> n >> q;

    int blockAmt = 0;
    while(q--) {

        int r, c;
        cin >> c >> r;
        r--;
        c--;

        lava[c][r].flip();

        FOR(dr, -1, 2) {
            if(r + dr < 0 || r + dr >= n)
                continue;

            if(lava[1 - c][r + dr])
                blockAmt += lava[c][r] ? -1 : 1;
        }

        if(!blockAmt)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}

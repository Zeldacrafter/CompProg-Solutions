#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

class ThreeNeighbors {
    public:
    vector<string> construct(int n) {
        vector<string> res(50);
        F0R(i, 50)
            res[i] = string(50, '.');

        for(int r = 1; n > 0 && r < 50; r += 3) {
            res[r][0] = res[r][1] = 'X';
            for(int c = 2; n > 0 && c < 50; ++c, n -= 2)
                res[r][c] = 'X';
        }
        if(n == -1)
            res[0][0] = 'X';

        return res;
    }
};

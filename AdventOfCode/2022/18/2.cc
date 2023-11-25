#include "../utils.cc"

set<tuple<int, int, int>> coords;

void solve() {
    int mnX = 1e9, mnY = 1e9, mnZ = 1e9,
        mxX = 0, mxY = 0, mxZ = 0;
    getInp([&](auto& cin, int) {
        int x, y, z; char c;
        cin >> x >> c >> y >> c >> z;
        ckmin(mnX, x);
        ckmin(mnY, y);
        ckmin(mnZ, z);
        ckmax(mxX, x);
        ckmax(mxY, y);
        ckmax(mxZ, z);
        coords.emplace(x, y, z);
    });

    set<tuple<int, int, int>> seenAll;
    FOR(sX, mnX - 1, mxX + 2) FOR(sY, mnY - 1, mxY + 2) FOR(sZ, mnZ - 1, mxZ + 2) {
        if(seenAll.count(mt(sX, sY, sZ)) || coords.count(mt(sX, sY, sZ))) continue;

        set<tuple<int, int, int>> seen;
        queue<tuple<int, int, int>> q;
        seen.emplace(sX, sY, sZ);
        q.emplace(sX, sY, sZ);

        bool foundEdge = false;

        while(!q.empty()) {
            auto [x, y, z] = q.front();
            q.pop();

            if(x < mnX || x > mxX || y < mnY || y > mxY || z < mnZ || z > mxZ) foundEdge = true;

            if(seenAll.count(mt(x, y, z))) {
                foundEdge = true;
                break;
            }

            FOR(i, -1, 2) FOR(j, -1, 2) FOR(k, -1, 2) 
                if(abs(i) + abs(j) + abs(k) == 1) {
                    int xx = x + i;
                    int yy = y + j;
                    int zz = z + k;

                    if(xx >= mnX - 1 && yy >= mnY - 1 && zz >= mnZ - 1 &&
                       xx <= mxX + 1 && yy <= mxY + 1 && zz <= mxZ + 1 &&
                       !coords.count(mt(xx, yy, zz)) && !seen.count(mt(xx, yy, zz))) {

                        seen.emplace(xx, yy, zz);
                        q.emplace(xx, yy, zz);
                   }
                }

        }

        if(foundEdge) seenAll.insert(ALL(seen));
    }

    ll res = 0;
    for(auto [x, y, z] : coords)
        FOR(i, -1, 2) FOR(j, -1, 2) FOR(k, -1, 2) 
            if(abs(i) + abs(j) + abs(k) == 1)
                res += seenAll.count(mt(x+i, y+j, z+k));
    cout << res << endl;
}


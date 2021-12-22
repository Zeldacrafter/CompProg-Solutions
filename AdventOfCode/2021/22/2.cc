#include "../utils.cc"

typedef tuple<int, int, int, int, int, int> cube;

bool contains(cube& a, cube& b) {
    auto [xMnA, xMxA, yMnA, yMxA, zMnA, zMxA] = a;
    auto [xMnB, xMxB, yMnB, yMxB, zMnB, zMxB] = b;

    return xMnA <= xMnB && xMxA >= xMxB &&
           yMnA <= yMnB && yMxA >= yMxB &&
           zMnA <= zMnB && zMxA >= zMxB;
}

bool intersect(cube& a, cube& b) {
    auto [xMnA, xMxA, yMnA, yMxA, zMnA, zMxA] = a;
    auto [xMnB, xMxB, yMnB, yMxB, zMnB, zMxB] = b;

    return xMnA <= xMxB && xMxA >= xMnB &&
           yMnA <= yMxB && yMxA >= yMnB &&
           zMnA <= zMxB && zMxA >= zMnB;
}

void removeAndAdd(vector<cube>& newCs, cube a, cube b) {
    auto [xMnA, xMxA, yMnA, yMxA, zMnA, zMxA] = a;
    auto [xMnB, xMxB, yMnB, yMxB, zMnB, zMxB] = b;

    if(contains(b, a)) return;

    if(!intersect(a, b)) {
        newCs.pb(a);
        return;
    }

    auto getPts = [](int mnA, int mxA, int mnB, int mxB) {
        vi splits;
        splits.pb(mnA);
        if(mnA < mnB && mnB < mxA) splits.pb(mnB);
        if(mnA < mxB && mxB < mxA) splits.pb(mxB);
        splits.pb(mxA);
        return splits;
    };
    vi xPts = getPts(xMnA, xMxA, xMnB, xMxB),
       yPts = getPts(yMnA, yMxA, yMnB, yMxB),
       zPts = getPts(zMnA, zMxA, zMnB, zMxB);

    F0R(i, SZ(xPts) - 1) F0R(j, SZ(yPts) - 1) F0R(k, SZ(zPts) - 1) {
        cube c = mt(xPts[i], xPts[i + 1],
                    yPts[j], yPts[j + 1],
                    zPts[k], zPts[k + 1]);
        if(!contains(b, c)) newCs.pb(c);
    }
}

ll area(cube& a) {
    auto [xMn, xMx, yMn, yMx, zMn, zMx] = a;
    return ((ll)xMx - xMn) * (yMx - yMn) * (zMx - zMn);
}

void solve() {
    vector<cube> cubes;
    getInp([&](auto& cin, int) {
        string s; char c;
        int xMn, xMx, yMn, yMx, zMn, zMx;
        cin >> s >> c >> c
            >> xMn >> c >> c >> xMx
            >> c >> c >> c
            >> yMn >> c >> c >> yMx
            >> c >> c >> c
            >> zMn >> c >> c >> zMx;

        cube newC = mt(xMn, xMx+1, yMn, yMx+1, zMn, zMx+1);
        vector<cube> newCubes;
        F0R(i, SZ(cubes))
            removeAndAdd(newCubes, cubes[i], newC);
        if(s == "on") newCubes.pb(newC);

        cubes = move(newCubes);
    });

    ll res = 0;
    for(cube& c : cubes)
        res += area(c);
    cout << res << endl;
}


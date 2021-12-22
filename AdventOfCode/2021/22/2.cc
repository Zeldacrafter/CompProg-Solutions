#include "../utils.cc"

typedef array<ii, 3> cube;

bool contains(cube& a, cube& b) {
    F0R(i, 3) 
        if(a[i].fi > b[i].fi || a[i].se < b[i].se)
            return false;
    return true;
}

bool intersect(cube& a, cube& b) {
    F0R(i, 3)
        if(a[i].fi > b[i].se || a[i].se < b[i].fi)
            return false;
    return true;
}

void removeAndAdd(vector<cube>& newCs, cube a, cube b) {
    if(contains(b, a)) return;

    if(!intersect(a, b)) {
        newCs.pb(a);
        return;
    }

    vvi pts(3);
    F0R(i, 3) {
        pts[i].pb(a[i].fi);
        if(a[i].fi < b[i].fi && b[i].fi < a[i].se) pts[i].pb(b[i].fi);
        if(a[i].fi < b[i].se && b[i].se < a[i].se) pts[i].pb(b[i].se);
        pts[i].pb(a[i].se);
    }

    F0R(i, SZ(pts[0]) - 1) F0R(j, SZ(pts[1]) - 1) F0R(k, SZ(pts[2]) - 1) {
        cube c = { mp(pts[0][i], pts[0][i + 1]), 
                   mp(pts[1][j], pts[1][j + 1]),
                   mp(pts[2][k], pts[2][k + 1])};
        if(!contains(b, c)) newCs.pb(c);
    }
}

ll volume(cube& a) {
    ll res = 1;
    F0R(i, 3) res *= a[i].se - a[i].fi;
    return res;
}

void solve() {
    vector<cube> cubes;
    getInp([&](auto& cin, int) {
        string s; char c;
        cube newC;
        F0R(i, 3) {
            if(!i) cin >> s;
            else cin >> c;
            cin >> c >> c >> newC[i].fi >> c >> c >> newC[i].se;
            ++newC[i].se;
        }
        vector<cube> newCubes;
        F0R(i, SZ(cubes))
            removeAndAdd(newCubes, cubes[i], newC);
        if(s == "on") newCubes.pb(newC);

        cubes = move(newCubes);
    });

    ll res = 0;
    for(cube& c : cubes)
        res += volume(c);
    cout << res << endl;
}


#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    set<int> rows, cols;
    F0R(r, SZ(ss)) {
        bool none = true;
        F0R(c, SZ(ss[c])) none &= ss[r][c] == '.';
        if(none) rows += r;
    }
    F0R(c, SZ(ss[0])) {
        bool none = true;
        F0R(r, SZ(ss)) none &= ss[r][c] == '.';
        if(none) cols += c;
    }

    vii coords;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) if(ss[r][c] == '#') coords.eb(r, c);

    ll res = 0;
    F0R(i, SZ(coords)) FOR(j, i + 1, SZ(coords)) {
        auto [r1, c1] = coords[i];
        auto [r2, c2] = coords[j];
        res += abs(r1 - r2) + abs(c1 - c2);
        FOR(i, min(r1, r2), max(r1, r2)) res += (1000000ll-1)*(rows < i);
        FOR(i, min(c1, c2), max(c1, c2)) res += (1000000ll-1)*(cols < i);
    }
    cout << res << endl;
}


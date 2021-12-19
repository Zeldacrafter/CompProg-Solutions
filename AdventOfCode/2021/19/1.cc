#include "../utils.cc"

#undef endl

typedef tuple<int, int, int> coord;

coord translate(const coord& c, int p) {
    auto [x, y, z] = c;
    if(p & (1 << 0)) x = -x;
    if(p & (1 << 1)) y = -y;
    if(p & (1 << 2)) z = -z;
    if(p & (1 << 3)) { int tmp = -1; swap(x, tmp); swap(z, x); swap(y, z); swap(tmp, y); }
    if(p & (1 << 4)) { int tmp = -1; swap(x, tmp); swap(z, x); swap(y, z); swap(tmp, y); }
    if(p & (1 << 5)) swap(x, y);
    return mt(x, y, z);
}

pair<bool, coord> match(vector<coord>& s1, const vector<coord>& s2) {
    F0R(origin1, SZ(s1)) {
        vector<coord> diffs1(SZ(s1));
        F0R(i, SZ(s1)) diffs1[i] = s1[i] - s1[origin1];

        F0R(origin2, SZ(s2)) {
            vector<coord> diffs2(SZ(s2));
            F0R(i, SZ(s2)) diffs2[i] = s2[i] - s2[origin2];

            F0R(perm, (1 << 6)) {
                vector<bool> matched(SZ(s2));
                vii match;
                F0R(i, SZ(s1)) F0R(j, SZ(s2)) {
                    if(diffs1[i] == translate(diffs2[j], perm)) {
                        matched[j] = true;
                        match.eb(i, j);
                        break;
                    }
                }
                if(SZ(match) >= 12) {
                    coord diff = s1[match[0].fi] - translate(s2[match[0].se], perm);
                    F0R(i, SZ(s2)) s1.pb(translate(s2[i], perm) + diff);
                    return mp(true, translate(mt(0, 0, 0), perm) + diff);
                }
            }
        }
    }
    return mp(false, mt(-1, -1, -1));
}

void solve() {
    vector<vector<coord>> inp;
    getInp([&](auto& cin, int) {
        static bool nextIsId = true;
        if(cin.peek() == -1) {
            nextIsId = true;
        } else if(nextIsId) {
            inp.eb();
            nextIsId = false;
        } else {
            int x, y, z; char c;
            cin >> x >> c >> y >> c >> z;
            inp.back().eb(x, y, z);
        }
    });

    vi done(SZ(inp), false);
    done[0] = true;

    // TODO: Use a set for 'matched'
    vector<coord> matched(ALL(inp[0])), sats(SZ(inp));

    while(find(ALL(done), false) != done.end()) {
        F0R(i, SZ(done)) if(!done[i]) {
            auto [b, c] = match(matched, inp[i]);
            if(done[i] |= b) {
                cout << "Match: " << i << endl;
                sort(ALL(matched)); // TODO Redundant with set
                matched.erase(unique(ALL(matched)), matched.end());

                sats[i] = c;
            }
        }
    }
    cout << SZ(matched) << endl;
}

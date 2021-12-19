#include "../utils.cc"

#undef endl
typedef tuple<int, int, int> coord;

coord translate(const coord& c, int p) {
    auto [x, y, z] = c;
    switch(p) {
        case 0: return mt( x,  y,  z);
        case 1: return mt(-x, -y,  z);
        case 2: return mt(-x,  y, -z);
        case 3: return mt( x, -y, -z);

        case 4: return mt( y,  z,  x);
        case 5: return mt(-y, -z,  x);
        case 6: return mt(-y,  z, -x);
        case 7: return mt( y, -z, -x);

        case 8:  return mt( z,  x,  y);
        case 9:  return mt(-z, -x,  y);
        case 10: return mt(-z,  x, -y);
        case 11: return mt( z, -x, -y);

        case 12: return mt(-z,  y,  x);
        case 13: return mt( z, -y,  x);
        case 14: return mt( z,  y, -x);
        case 15: return mt(-z, -y, -x);

        case 16: return mt(-y,  x,  z);
        case 17: return mt( y, -x,  z);
        case 18: return mt( y,  x, -z);
        case 19: return mt(-y, -x, -z);

        case 20: return mt(-x,  z,  y);
        case 21: return mt( x, -z,  y);
        case 22: return mt( x,  z, -y);
        case 23: return mt(-x, -z, -y);

        default: assert(false);
    }
    return c;
}

bool match(set<coord>& s1, const vector<coord>& s2) {
    for(coord o1 : s1) {
        for(coord o2 : s2) {
            F0R(perm, 24) {
                int match = 0;
                coord diff;
                for(coord x : s1) for(coord y : s2) {
                    if(x - o1 == translate(y - o2, perm)) {
                        diff = x - translate(y, perm);
                        match++;
                        break;
                    }
                }
                if(match >= 12) {
                    for(coord x : s2)
                        s1.insert(translate(x, perm) + diff);
                    return true;
                }
            }
        }
    }
    return false;
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

    set<coord> matched(ALL(inp[0]));
    while(find(ALL(done), false) != done.end()) {
        F0R(i, SZ(done)) if(!done[i]) {
            if(done[i] |= match(matched, inp[i]))
                cout << "Match: " << i << endl;
        }
    }
    cout << SZ(matched) << endl;
}

#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    map<char, set<ii>> nodes;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) if(ss[r][c] != '.') nodes[ss[r][c]].emplace(r, c);

    auto in = [&](ii p) { return min(p.fi, p.se) >= 0 && p.fi < SZ(ss) && p.se < SZ(ss[0]); };

    set<ii> antinodes;
    for(auto& [c, ns] : nodes) {
        for(auto p1 : ns) for(auto p2 : ns) if(p1 != p2) {
            ii d = p1 - p2;
            for(int i = 0; in(p1 + i*d) || in(p1 - i*d); ++i) {
                if(in(p1 + i*d)) antinodes.insert(p1 + i*d);
                if(in(p1 - i*d)) antinodes.insert(p1 - i*d);
            }
        }
    }
    cout << SZ(antinodes) << endl;
}


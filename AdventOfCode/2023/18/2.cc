#include "../utils.cc"

const vi DR {-1, 1, 0, 0}, DC {0, 0, -1, 1};
const vii dirs = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};

void solve() {
    vector<tuple<ll, ll, ll>> vertLines; // col, startR, endR
    map<ll, vector<pair<ll, ll>>> rowMap;  // row -> pairs<startC, endC>
    vector<ll> rows = {0};

    pair<ll, ll> pos(0, 0);
    getInp([&](auto& cin, int) {
        string s; ll amt;
        cin >> s >> amt >> s;
        amt = strtoul(s.substr(2, 5).c_str(), nullptr, 16);
        ii dir = dirs[s[SZ(s) - 2] - '0'];

        pair<ll, ll> newPos = pos + amt*dir;
        if(dir.fi) {
            vertLines.eb(pos.se, min(pos.fi, newPos.fi), max(pos.fi, newPos.fi)); 
        } else {
            rowMap[pos.fi].eb(min(pos.se, newPos.se), max(pos.se, newPos.se));
            rows.pb(newPos.fi);
        }
        pos += amt*dir;
    });

    sort(ALL(vertLines));
    sort(ALL(rows));
    rows.erase(unique(ALL(rows)), rows.end());

    auto getInAmt = [&](int r) {
        ll res = 0;
        bool in = false;

        ll lastIn;
        bool dirBeforeRow, inBeforeRow;
        for(auto [col, startR, endR] : vertLines) {
            if(r < startR || r > endR) continue;

            bool rowStarts = any_of(ALL(rowMap[r]), [&](auto p) { return col == p.fi; });
            bool rowEnds = any_of(ALL(rowMap[r]), [&](auto p) { return col == p.se; });
            assert(!rowStarts || !rowEnds);

            if(rowStarts) {
                dirBeforeRow = r == endR;
                inBeforeRow = in;
            }

            if(!in) {
                in = true;
                lastIn = col;
            } else {
                if(rowEnds) {
                    // Switch `in` iff the path continues in the same direction after the horizontal
                    // down -> horizontal -> down OR up -> horizontal -> up
                    in = inBeforeRow ^ (dirBeforeRow != (r == endR));
                } else if(!rowStarts) {
                    in = false;
                }
                if(!in) res += col - lastIn + 1;
            }
        }
        return res;
    };

    ll res = 0, lastR = -1e9;
    for(ll r : rows) {
        res += getInAmt(r);
        if(lastR != -1e9) res += max(0ll, r - lastR - 1)*getInAmt(lastR + 1);
        lastR = r;
    }

    dout << res << endl;
}


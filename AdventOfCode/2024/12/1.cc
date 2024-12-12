#include "../utils.cc"

vii ds = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

vector<string> ss;

bool ok(ii p, char ch) {
    return min(p.fi, p.se) >= 0 && p.fi < SZ(ss) && p.se < SZ(ss[0]) && ss[p.fi][p.se] == ch;
}

set<ii> coords(int r, int c) {
    set<ii> res;
    res.emplace(r, c);

    queue<ii> q;
    q.emplace(r, c);
    while(SZ(q)) {
        ii p = q.front();
        q.pop();
        for(ii d : ds) {
            if(ok(p + d, ss[r][c]) && res.insert(p + d).se)
                q.push(p + d);
        }
    }
    return res;
}

void solve() {
    ll res = 0;

    ss = getInp();

    set<ii> seen;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        if(seen.contains({r, c})) continue;

        set<ii> ps = coords(r, c);
        seen |= ps;

        int perim = 0;
        for(ii p : ps)
            for(ii d : ds) 
                perim += !ok(p + d, ss[r][c]);

        res += perim * SZ(ps);
    }

    cout << res << endl;
}


#include "../utils.cc"

vii dirs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

void solve() {
    vector<string> ss = getInp();

    auto ok = [&](ii pp) { return min(pp.fi, pp.se) >= 0 && pp.fi < SZ(ss) && pp.se < SZ(ss[0]) && ss[pp.fi][pp.se] != '#'; };

    ii start, end;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        if(ss[r][c] == 'S') start = mp(r, c);
        if(ss[r][c] == 'E') end = mp(r, c);
    }

    auto getDists = [&](ii s) {
        map<ii, int> dists;
        queue<ii> q;

        dists[s] = 0;
        q.push(s);
        while(SZ(q)) {
            ii p = q.front(); q.pop();
            F0R(i, 4) {
                ii pp = p + dirs[i];
                if(!ok(pp) || dists.count(pp)) continue;
                dists[pp] = dists[p] + 1;
                q.push(pp);
            }
        }
        return dists;
    };

    map<ii, int> distS = getDists(start),
                 distE = getDists(end);

    int res = 0;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        ii p(r, c);
        if(!ok(p)) continue;

        F0R(i, 4) FOR(j, i, 4) {
            ii pp = p + dirs[i] + dirs[j];
            if(ok(pp) && distS[p] + distE[pp] + 2 + 50 <= distS[end]) res++;
        }
    }
    cout << res << endl;
}


#include "../utils.cc"

const vii dirs { mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1) };

void solve() {
    vector<string> ss = getInp();

    // dist, pos, previous dir
    set<tuple<ll, ii, ii>> q;
    map<pair<ii, ii>, ll> dist;
    for(ii dir : { mp(1, 0), mp(0, 1) }) {
        q.emplace(0, mp(0, 0), dir);
        dist[{mp(0, 0), dir}] = 0;
    }

    while(SZ(q)) {
        auto [d, p, dir] = *q.begin();
        auto [r, c] = p;
        q.erase(q.begin());

        if(dist[{p, dir}] < d) continue;
        if(r == SZ(ss) - 1 && c == SZ(ss[r]) - 1) {
            cout << d << endl;
            return;
        }

        F0R (i, 4) {
            if ((dirs[i] & dir) != mp(0, 0)) continue;
            ll dNew = d;
            FOR (j, 1, 4) {
                ii pp = p + j*dirs[i];
                auto [rr, cc] = pp;

                if (min(cc, rr) < 0 || rr >= SZ(ss) || cc >= SZ(ss[rr])) break;

                dNew += ss[rr][cc] - '0';
                if (!dist.count({pp, dirs[i]}) || dist[{pp, dirs[i]}] > dNew) {
                    dist[{pp, dirs[i]}] = dNew;
                    q.emplace(dNew, pp, dirs[i]);
                }
            }
        }
    }
    assert(false);
}

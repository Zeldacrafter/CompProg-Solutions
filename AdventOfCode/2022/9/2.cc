#include "../utils.cc"

#define N 10

int sgn(int val) {
    return (0 < val) - (val < 0);
}

void solve() {
    set<ii> seen;

    vi xs(N), ys(N);

    getInp([&](auto& cin, int) {
        char c; int dist; cin >> c >> dist;

        F0R(i, dist) {
            switch(c) {
                case 'R': xs[0]++; break;
                case 'L': xs[0]--; break;
                case 'U': ys[0]++; break;
                case 'D': ys[0]--; break;
            }

            FOR(i, 1, N) {
                int dx = xs[i - 1] - xs[i],
                    dy = ys[i - 1] - ys[i];

                if(!dx && abs(dy) == 2)
                    ys[i] += sgn(dy);
                else if (!dy && abs(dx) == 2)
                    xs[i] += sgn(dx);
                else if(abs(dx) + abs(dy) > 2) {
                    ys[i] += sgn(dy);
                    xs[i] += sgn(dx);
                }
            }

            seen.insert(mp(xs.back(), ys.back()));
        }
    });
    cout << SZ(seen) << endl;

}


#include "../utils.cc"

const vi DR = {1, -1, 0, 0},
         DC = {0, 0, 1, -1};

void solve() {
    vector<string> ss = getInp();

    ii end;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        if(ss[r][c] == 'S') {
            ss[r][c] = 'a';
        }
        if(ss[r][c] == 'E') {
            end = mp(r, c);
            ss[r][c] = 'z';
        }
    }
            
    auto find = [&](ii s) {
        queue<tuple<int, int, int>> q;
        q.emplace(s.fi, s.se, 0);
        set<ii> seen;
        seen.insert(s);

        while(SZ(q)) {
            auto [r, c, d] = q.front();
            q.pop();

            if(mp(r, c) == end) return d;

            F0R(i, 4) {
                int rr = r + DR[i],
                    cc = c + DC[i];

                if(min(rr,cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0]) ||
                        seen.count(mp(rr, cc)) || 
                        ss[rr][cc] - ss[r][c] > 1)
                    continue;

                q.emplace(rr, cc, d + 1);
                seen.emplace(rr, cc);
            }
        }
        return (int)1e9;
    };

    int res = 1e9;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0]))
        if(ss[i][j] == 'a')
            ckmin(res, find(mp(i, j)));
    cout << res << endl;
}


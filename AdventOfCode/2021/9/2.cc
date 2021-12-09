#include "../utils.cc"

vi dr{1, -1, 0, 0}, dc{0, 0, 1, -1};

void solve() {
    vector<string> s = getInp();

    vi id;
    queue<tuple<int, int, int>> q;
    F0R(r, SZ(s)) {
        F0R(c, SZ(s[r])) {
            bool ok = true;
            F0R(i, 4) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(min(rr, cc) < 0 || rr >= SZ(s) || cc >= SZ(s[r])) continue;
                ok &= s[r][c] < s[rr][cc];
            }
            if(ok) {
                res += s[r][c] - '0' + 1;
                q.emplace(r, c, SZ(id));
                id.pb(0);
            }

        }
    }
    vvi seen(SZ(s), vi(SZ(s[0])));
    while(SZ(q)) {
        auto [r, c, k] = q.front(); q.pop();
        id[k]++;
        F0R(i, 4) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(min(rr, cc) < 0 || rr >= SZ(s) || cc >= SZ(s[r])) continue;
            if(seen[rr][cc] || s[rr][cc] == '9' || s[rr][cc] < s[r][c]) continue;
            seen[rr][cc] = true;
            q.emplace(rr, cc, k);
        }

    }
    
    sort(ALL(id), greater<int>());
    cout << id[0]*id[1]*id[2] << endl;
}


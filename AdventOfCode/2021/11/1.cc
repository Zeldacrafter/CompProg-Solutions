#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    ll res = 0;
    F0R(_, 100) {
        F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) ss[r][c]++;

        queue<ii> todo;
        F0R(r, SZ(ss)) F0R(c, SZ(ss[0]))
            if(ss[r][c] == '9' + 1)
                todo.emplace(r, c);

        vii zero;
        while(SZ(todo)) {
            zero.pb(todo.front());
            auto [r, c] = todo.front();
            todo.pop();

            for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}) {
                int rr = r + dr, cc = c + dc;
                if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0])) continue;
                ss[rr][cc]++;
                if(ss[rr][cc] == '9' + 1)
                    todo.emplace(rr, cc);
            }
        }

        for(auto [r, c] : zero) ss[r][c] = '0';

        res += SZ(zero);
    }

    cout << res << endl;
}


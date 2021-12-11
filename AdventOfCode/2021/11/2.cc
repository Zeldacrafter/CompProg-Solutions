#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    for(int cnt = 1;; ++cnt) {
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

            for(int i : {-1, 0, 1}) for(int j : {-1, 0, 1}) {
                int rr = r + i, cc = c + j;
                if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0])) continue;
                ss[rr][cc]++;
                if(ss[rr][cc] == '9' + 1)
                    todo.emplace(rr, cc);
            }
        }

        for(auto [r, c] : zero) ss[r][c] = '0';

        if(SZ(zero) == SZ(ss)*SZ(ss[0])) {
            cout << cnt << endl; 
            return;
        }
    }
}


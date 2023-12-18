#include "../utils.cc"

const vi DR {-1, 1, 0, 0}, DC {0, 0, -1, 1};
map<char, ii> dirs = { {'R', mp(0, 1)}, {'L', mp(0, -1)}, {'U', mp(-1, 0)}, {'D', mp(1, 0)} };

void solve() {
    set<ii> seen;
    ii pos(0, 0);
    getInp([&](auto& cin, int) {
        char dir; int amt;
        cin >> dir >> amt;

        F0R(i, amt) {
            pos += dirs[dir];
            seen.insert(pos);
        }
    });

    queue<ii> q;
    seen.emplace(1, 1);
    q.emplace(1, 1);
    while(SZ(q)) {
        auto [r, c] = q.front();
        q.pop();

        F0R(i, 4) {
            int rr = r + DR[i],
                cc = c + DC[i];
            if(seen.emplace(rr, cc).se) q.emplace(rr, cc);
        }
    }

    cout << SZ(seen) << endl;
}


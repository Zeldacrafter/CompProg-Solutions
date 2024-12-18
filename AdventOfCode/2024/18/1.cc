#include "../utils.cc"

int SIZE = 71;
vii dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int get_dist(set<ii>& bad) {
    queue<ii> q;
    map<ii, int> dist;
    q.emplace(0, 0);
    while(SZ(q)) {
        ii pos = q.front(); q.pop();

        if(pos == mp(SIZE - 1, SIZE - 1)) return dist[pos];

        F0R(i, 4) {
            if(min((pos + dirs[i]).fi, (pos + dirs[i]).se) < 0 || 
                    max((pos + dirs[i]).fi, (pos + dirs[i]).se) >= SIZE ||
                    bad.count(pos + dirs[i]) || dist.count(pos + dirs[i])) continue;
            q.push(pos + dirs[i]);
            dist[pos + dirs[i]] = dist[pos] + 1;
        }
    }
    assert(false);
    return -1;
}

void solve() {
    set<ii> bad;
    getInp([&](auto& cin, int i) {
        if(i >= 1024) return;

        char _; int x, y;
        cin >> x >> _ >> y;
        bad.emplace(x, y);
    });
    cout << pp(get_dist(bad)) << endl;
}


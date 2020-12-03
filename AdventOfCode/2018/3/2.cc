#include "../template.cc"

int cnt[1001][1001] = {};

void solve() {
    vector<tuple<int, int, int, int, int>> a;
    vector<string> ss = getInp([&](auto& cin, int i) {
        char c;
        int id, x, y, w, h;
        cin >> c >> id >> c >> x >> c >> y >> c >> w >> c >> h;
        a.eb(id, x, y, w, h);

        FOR(i, x, x + w)
            FOR(j, y, y + h)
                cnt[i][j]++;
    });
    for(auto [id, x, y, w, h] : a) {
        bool ok = true;
        FOR(i, x, x + w)
            FOR(j, y, y + h)
                ok &= cnt[i][j] == 1;
        if(ok)
            cout << id << endl;
    }
}


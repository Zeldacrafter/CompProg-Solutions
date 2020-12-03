#include "../template.cc"

int cnt[1001][1001] = {};

void solve() {
    ll res = 0;
    vector<string> ss = getInp([&](auto& cin, int i) {
        char c;
        int id, x, y, w, h;
        cin >> c >> id >> c >> x >> c >> y >> c >> w >> c >> h;

        FOR(i, x, x + w)
            FOR(j, y, y + h)
                cnt[i][j]++;
    });
    F0R(i, 1001) F0R(j, 1001) res += cnt[i][j] > 1;
    cout << res << endl;
}


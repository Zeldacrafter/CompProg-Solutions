#include "../template.cc"

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
    ll res = 0;
    vector<pair<char, int>> a;
    getInp([&](auto& cin, int) {
        char c;
        int x;
        cin >> c >> x;
        a.eb(c, x);
    });

    int x = 0, y = 0;
    int offset = 0;
    for(auto [d, amt] : a) {
        if(d == 'F') {
            x += amt*dx[offset];
            y += amt*dy[offset];
        } else if(d == 'S') {
            y -= amt;
        } else if(d == 'E') {
            x += amt;
        } else if(d == 'W') {
            x -= amt;
        } else if(d == 'N') {
            y += amt;
        } else if(d == 'L') {
            offset = ((offset - amt/90) % 4 + 4) % 4;
        } else if(d == 'R') {
            offset = (offset + amt/90) % 4;
        }
    }
    cout << abs(x) + abs(y) << endl;
}


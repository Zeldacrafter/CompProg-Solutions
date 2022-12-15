#include "../utils.cc"

void solve() {
    ll beacons_on_line = 0;
    set<ii> seen;

    vector<string> ss = getInp([&](auto& cin, int) {
        string s; char c; ll x1, y1, x2, y2;
        cin >> s >> s >> c >> c
            >> x1 >> c >> c >> c >> y1
            >> c >> s >> s >> s >> s >> c >> c 
            >> x2 >> c >> c >> c >> y2;

        ll targetY = 2000000;

        ll dist_beacon = abs(x1 - x2) + abs(y1 - y2);

        if(y2 == targetY && !seen.count(mp(x2, y2))) beacons_on_line++;
        for(ll dx = 0; abs(y1 - targetY) + dx <= dist_beacon; ++dx) {
            seen.emplace(x1 + dx, targetY);
            seen.emplace(x1 - dx, targetY);
        }
    });
    cout << SZ(seen) - beacons_on_line << endl;
}


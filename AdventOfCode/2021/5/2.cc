#include "../utils.cc"

void solve() {
    map<ii, int> amt;
    getInp([&](auto& cin, int) {
        int x1, y1, x2, y2; char c;
        cin >> x1 >> c >> y1 >> c >> c >> x2 >> c >> y2;

        if(x1 == x2) {
            if(y1 > y2) swap(y1, y2);
            FOR(i, y1, y2 + 1) amt[mp(x1, i)]++;
        } else if (y1 == y2) {
            if(x1 > x2) swap(x1, x2);
            FOR(i, x1, x2 + 1) amt[mp(i, y1)]++;
        } else {
            if(x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }

            if(y1 > y2) {
                F0R(i, y1 - y2 + 1) 
                    amt[mp(x1 + i, y1 - i)]++;
            } else {
                F0R(i, y2 - y1 + 1)
                    amt[mp(x1 + i, y1 + i)]++;
            }
        }
    });

    ll res = 0;
    for(auto [k, v] : amt)
        res += v > 1;
    cout << res << endl;
}


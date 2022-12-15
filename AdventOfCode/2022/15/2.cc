#include "../utils.cc"

const ll X_MIN = 0, Y_MIN = 0,
         X_MAX = 4000000, Y_MAX = 4000000;

void solve() {
    vector<tuple<ll, ll, ll, ll>> coords;

    getInp([&](auto& cin, int) {
        string s; char c; ll x1, y1, x2, y2;
        cin >> s >> s >> c >> c
            >> x1 >> c >> c >> c >> y1
            >> c >> s >> s >> s >> s >> c >> c 
            >> x2 >> c >> c >> c >> y2;

        coords.eb(x1, y1, x2, y2);
    });
    
    FOR(y, Y_MIN, Y_MAX + 1) {
        vector<pair<ll, ll>> is;
        for(auto [x1, y1, x2, y2] : coords) {
            ll dY = abs(y - y1),
               d = abs(y1 - y2) + abs(x1 - x2);
            if(dY <= d) is.eb(x1 + (dY - d), x1 - (dY - d));
        }
        sort(ALL(is));

        ll x = X_MIN;
        for (auto [l, r] : is) {
            if(x < l) {
                cout << x*4000000 + y << endl;
                return;
            }
            ckmax(x, r + 1);
        }
        if(x <= X_MAX) {
            cout << x*4000000 + y << endl;
            return;
        }
    }
}


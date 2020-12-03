#include "../template.cc"

#define BEGIN 0
#define WAKE 1
#define SLEEP 2

void solve() {
    vector<tuple<ll, int, int>> a;
    vector<string> ss = getInp([&](auto& cin, int i) {
        char c;
        ll y, m, d, h, min;
        cin >> c >> y >> c >> m >> c >> d >> h >> c >> min >> c;

        d += m*30;
        h += d*24;
        min += h*60;

        string s;
        cin >> s;
        int mode = -1;
        int id = -1;
        if(s == "Guard") {
            mode = BEGIN;
            cin >> c >> id;
        } else if(s == "wakes") {
            mode = WAKE;
        } else {
            mode = SLEEP;
        }
        a.eb(min, mode, id);
    });

    sort(ALL(a));
    ll currT = 0, currId = 0; 
    bool asleep = false;
    map<pair<int, int>, ll> amtSleep;

    for(auto [t, mode, id] : a) {
        if(asleep) {
            FOR(i, currT, t)
                amtSleep[mp(currId, i % 60)]++;
        }
        switch(mode) {
            case BEGIN:
                currId = id;
                asleep = false;
                break;
            case WAKE:
                asleep = false;
                break;
            case SLEEP:
                asleep = true;
                break;
        }
        currT = t;
    }

    int resId = 0, resMin = 0;

    for(auto [k, v] : amtSleep)
        F0R(i, 60)
            if(amtSleep[mp(resId, resMin)] < v) {
                resId = k.fi;
                resMin = k.se;
            }

    cout << resMin*resId << endl;
}


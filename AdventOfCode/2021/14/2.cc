#include "../utils.cc"

void solve() {
    map<pair<char, char>, ll> pairAmt;
    vector<tuple<char, char, char>> rules;
    pair<char, char> first, last;

    getInp([&](auto& cin, int) {
        if(!SZ(pairAmt)) {
            string start; cin >> start;

            F0R(i, SZ(start) - 1)
                pairAmt[mp(start[i], start[i + 1])]++;
            first = mp(start[0], start[1]);
            last = mp(start[SZ(start) - 2], start.back());
        } else {
            char c1, c2, c, c3;
            if(cin >> c1 >> c2 >> c >> c >> c3)
                rules.eb(c1, c2, c3);
        }
    });

    F0R(_, 40) {
        map<pair<char, char>, ll> newCurr;
        pair<char, char> newFirst = first, newLast = last;

        for(auto [c1, c2, c] : rules) {
            if(pairAmt.count(mp(c1, c2))) {
                newCurr[mp(c1, c)] += pairAmt[mp(c1, c2)];
                newCurr[mp(c, c2)] += pairAmt[mp(c1, c2)];
            } else {
                newCurr[mp(c1, c2)] += pairAmt[mp(c1, c2)];
            }
            if(pairAmt.count(first)) newFirst = mp(c1, c);
            if(pairAmt.count(last)) newLast = mp(c, c2);
        }

        pairAmt = newCurr;
    }

    map<char, ll> amt;
    for(auto [p, x] : pairAmt) {
        amt[p.fi] += x + (p == first);
        amt[p.se] += x + (p == last);
    }

    ll mx = numeric_limits<ll>::min(), mn = numeric_limits<ll>::max();
    for(auto [_, x] : amt) {
        assert(x % 2 == 0 && "Every letter should be double-counted");
        ckmax(mx, x/2);
        ckmin(mn, x/2);
    }
    cout << mx - mn << endl;
}


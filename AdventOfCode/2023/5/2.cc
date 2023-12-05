#include "../utils.cc"

typedef pair<ll, ll> llll;
typedef vector<llll> vllll;

void solve() {
    vllll seeds;
    vector<vector<tuple<ll, ll, ll>>> conv;

    getInp([&](auto& cin, int i) {
        if(!i) {
            string s; ll k1, k2; cin >> s;
            while(cin >> k1 >> k2) seeds.eb(k1, k1 + k2);
        } else if(isdigit(cin.peek())) {
            tuple<ll, ll, ll> v; cin >> v;
            conv.back().pb(v);
        } else if(!cin.eof()) {
            conv.eb();
        }
    });

    ll res = numeric_limits<ll>::max();
    for(auto [lStart, rStart] : seeds) {
        vllll ranges {mp(lStart, rStart)};

        for(auto& v : conv) {
            vllll modified;
            for(auto [dst, src, sz] : v) {
                vllll unmodified;
                for(auto [l, r] : ranges) {
                    llll before(l, min(r, src)),
                         inside(max(l, src), min(src + sz, r)),
                         after(max(src + sz, l), r);
                    if(before.fi < before.se) unmodified.pb(before);
                    if(inside.fi < inside.se) modified.pb(inside + dst - src);
                    if(after.fi < after.se) unmodified.pb(after);
                }
                ranges = unmodified;
            }
            ranges.insert(ranges.end(), ALL(modified));
        }
        ckmin(res, min_element(ALL(ranges))->fi);
    }
    cout << res << endl;
}

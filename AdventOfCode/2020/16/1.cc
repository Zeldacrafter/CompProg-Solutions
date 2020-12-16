#include "../template.cc"

vi toInts(vector<string> ss) {
    vi res;
    for(string& s : ss) 
        res.pb(stoi(s));
    return res;
}

ii toInts(pair<string, string> ss) {
    return mp(stoi(ss.fi), stoi(ss.se));
}

void solve() {
    vector<string> ss = getInp();

    bitset<1000> seen;

    int stage = 0;
    ll res = 0;
    for(string& s : ss) {
        if(s == "") {
            continue;
        } else if(s == "your ticket:" || s == "nearby tickets:") {
            stage++;
        } else if(!stage) {
            // New key
            auto [key, rangesS] = splitP(s, ": ");
            vector<string> ranges = split(rangesS, " or ");
            for(string& range : ranges) {
                auto [from, to] = toInts(splitP(range, "-"));
                FOR(i, from, to + 1)
                    seen[i] = true;
            }
        } else if(stage == 1) {
            // My ticket
        } else {
            // Nearby tickets
            assert(stage == 2);

            vi vals = toInts(split(s, ","));
            for(int v : vals)
                if(!seen[v])
                    res += v;
        }
    }

    cout << res << endl;
}


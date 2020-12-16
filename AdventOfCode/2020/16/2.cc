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

const int POS_AMT = 20;

void solve() {
    vector<string> ss = getInp();

    bitset<1000> seen;
    map<string, bitset<1000>> rangesMp;
    map<string, set<int>> maybePos;

    auto adjustPoss = [&](vi& a) {
        F0R(i, SZ(a))
            for(auto& [k, seens] : rangesMp)
                if(!seens[a[i]])
                    maybePos[k].erase(i);
    };

    vi myTicket;
    int stage = 0;
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
                FOR(i, from, to + 1) {
                    seen[i] = true;
                    rangesMp[key][i] = true;
                }
            }
            F0R(i, POS_AMT) maybePos[key].insert(i);
        } else if(stage == 1) {
            // My ticket

            myTicket = toInts(split(s, ","));
            adjustPoss(myTicket);
        } else {
            // Nearby tickets
            assert(stage == 2);

            vi vals = toInts(split(s, ","));
            if(all_of(ALL(vals), [&](int x) { return seen[x]; }))
                adjustPoss(vals);
        }
    }

    // find unique mapping of positions
    map<string, int> resMap;
    for(auto& [k, v] : maybePos) resMap[k] = -1;

    for(bool change = false; ; change = false) {

        for(auto& [k, poss] : maybePos) {
            if(resMap[k] != -1) continue;

            if(SZ(poss) == 1) {
                change = true;
                resMap[k] = *poss.begin();

                for(auto& [k2, poss2] : maybePos)
                    poss2.erase(resMap[k]);
            }
        }

        if(!change) break;
    }

    // Get result
    ll res = 1;
    for(auto& [k, i] : resMap)
        if(k[0] == 'd' && k[1] == 'e')
            res *= myTicket[i];

    cout << res << endl;
}


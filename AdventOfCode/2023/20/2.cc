#include "../utils.cc"

void solve() {
    map<string, int> toInd;
    vector<char> type;
    vvi outs, outsInv;
    vector<bool> on;
    vector<map<int, bool>> conjFrom;

    auto addElem = [&](string s) {
        if(toInd.count(s)) return toInd[s];
        int i = toInd[s] = SZ(type);
        type.pb(-1);
        outs.eb();
        outsInv.eb();
        on.pb(false);
        conjFrom.eb();
        return i;
    };
   
    getInp([&](auto& cin, int) {
        string inp, s; cin >> inp >> s;

        char t = inp[0];
        if (inp != "broadcaster") inp = inp.substr(1);
        int i = addElem(inp);
        type[i] = t;

        while(cin >> s) {
            if(s.back() == ',') s.pop_back();
            int j = addElem(s);
            outs[i].pb(j);
        }
    });

    F0R(inp, SZ(outs)) for(int out : outs[inp]) {
        if(type[out] == '&') conjFrom[out][inp] = false;
        outsInv[out].pb(inp);
    }

    set<int> wantedInps(ALL(outsInv[outsInv[toInd["rx"]][0]]));
    vi prevLow(SZ(outs), -1), cntLow(SZ(outs));
    for(ll t = 1, res = 1, resCnt = 0;; ++t) {
        queue<tuple<int, int, bool>> q;
        q.emplace(toInd["broadcaster"], -1, false);
        while(SZ(q)) {
            auto [inp, from, high] = q.front();
            q.pop();

            if(!high) {
                if(cntLow[inp] == 5 && wantedInps < inp) {
                    res = lcm(res, t - prevLow[inp]);
                    ++resCnt;
                }
                prevLow[inp] = t;
                cntLow[inp]++;
            }

            if(resCnt == SZ(wantedInps)) {
                cout << res << endl;
                return;
            }

            switch(type[inp]) {
                case 'b':
                    for(int out : outs[inp]) q.emplace(out, inp, high);
                    break;
                case '%':
                    if(!high) {
                        on[inp] = !on[inp];
                        for(int out : outs[inp]) q.emplace(out, inp, on[inp]);
                    }
                    break;
                case '&': {
                    conjFrom[inp][from] = high;
                    bool new_t = !all_of(ALL(conjFrom[inp]), [](auto p) { return p.se; });
                    for(int out : outs[inp]) q.emplace(out, inp, new_t);
                    break;}
                case -1:
                    continue; // Not an input
                default:
                    assert(false);
            }

        }
    }
}

#include "../utils.cc"

void solve() {
    map<string, function<ll(map<char, ii>)>> fs;
    fs["A"] = [&](map<char, ii> m) { 
        ll res = 1;
        for(auto [_, range] : m) {
            if(range.fi > range.se) return 0ll;
            res *= range.se - range.fi + 1;
        }
        return res; 
    };
    fs["R"] = [&](map<char, ii>) { return 0ll; };

    getInp([&](auto& cin, int) {
        string s;
        if(!(cin >> s)) return;
        auto [name, instrs] = splitP(s, "{");
        instrs.pop_back();

        if(name != "") {
            fs[name] = [&fs, instrs](map<char, ii> m) {
                ll res = 0;
                for(string instr : split(instrs, ",")) {
                    if(SZ(instr) > 1 && (instr[1] == '<' || instr[1] == '>')) {
                        auto [cond, f] = splitP(instr, ":");
                        char var = cond[0],
                             type = cond[1];
                        int amt = stoi(cond.substr(2));

                        map<char, ii> newM(m);
                        if(type == '<') {
                            newM[var] = mp(m[var].fi, min(m[var].se, amt - 1));
                            m[var] = mp(max(m[var].fi, amt), m[var].se);
                        } else if(type == '>') {
                            newM[var] = mp(max(m[var].fi, amt + 1), m[var].se);
                            m[var] = mp(m[var].fi, min(m[var].se, amt));
                        }
                        res += fs[f](newM);
                    } else {
                        res += fs[instr](m);
                    }
                }
                return res;
            };
        }
    });

    map<char, ii> ranges;
    for(char c : string("xmas"))
        ranges[c] = mp(1, 4000);
    cout << fs["in"](ranges) << endl;
}


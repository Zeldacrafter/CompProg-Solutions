#include "../utils.cc"

void solve() {
    map<string, function<bool(map<char, int>&)>> fs;
    fs["A"] = [&](map<char, int>&) { return true; };
    fs["R"] = [&](map<char, int>&) { return false; };

    ll res = 0;
    getInp([&](auto& cin, int) {
        string s;
        if(!(cin >> s)) return;
        auto [name, instrs] = splitP(s, "{");
        instrs.pop_back();

        if(name == "") {
            map<char, int> m;
            for(string instr : split(instrs, ",")) 
                m[instr[0]] = stoi(instr.substr(2));
            if(fs["in"](m)) 
                for(auto [_, amt] : m) res += amt;
        } else {
            fs[name] = [&fs, instrs](map<char, int>& m) {
                for(string instr : split(instrs, ",")) {
                    if(SZ(instr) > 1 && (instr[1] == '<' || instr[1] == '>')) {
                        auto [cond, f] = splitP(instr, ":");
                        char var = cond[0],
                             type = cond[1];
                        int amt = stoi(cond.substr(2));

                        if(type == '<' && m[var] < amt) return fs[f](m);
                        if(type == '>' && m[var] > amt) return fs[f](m);
                    } else {
                        return fs[instr](m);
                    }
                }
                assert(false);
            };
        }
    });
    cout << res << endl;
}


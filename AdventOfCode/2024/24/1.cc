#include "../utils.cc"

void solve() {
    vector<tuple<string, string, string, string>> ops;
    map<string, bool> initVals;

    auto doOp = [&](map<string, bool>& v, string s, string op, string s2, string target) {
        if(!v.count(s) || !v.count(s2)) return false;

        if(op == "OR") v[target] = v[s] || v[s2];
        else if(op == "AND") v[target] = v[s] && v[s2];
        else if(op == "XOR") v[target] = v[s] ^ v[s2];
        else assert(false);

        return true;
    };

    getInp([&](auto& cin, int) {
            string s; 
            if(!(cin >> s)) return;
            if(s.back() == ':') {
                s.pop_back();
                bool b; cin >> b;
                initVals[s] = b;
            } else {
                string op, s2, _, target;
                cin >> op >> s2 >> _ >> target;
                ops.eb(s, op, s2, target);
            }
    });

    auto toInp = [](string p, int n) {
        return p + (n < 10 ? "0" : "") + to_string(n);
    };
    
    auto toLL = [&](const string& str) {
        ll res = 0;
        F0R(i, SZ(str)) res = res*2 + (str[i] - '0');
        return res;
    };

    auto toBinary = [&](map<string, bool>& vals, string prefix) {
        string str = "";
        for(int i = 0; ; ++i) {
            if(!vals.count(toInp(prefix, i))) break;
            str = to_string(vals[toInp(prefix, i)]) + str;
        }
        assert(str != "");
        return str;
    };

    auto sim = [&](map<string, bool> vals) {
        vector<bool> done(SZ(ops));
        int ok = 0;
        for(int i = 0; ok < SZ(done); i = (i + 1) % SZ(ops)) {
            if(done[i]) continue;
            auto [s1, op, s2, target] = ops[i];
            done[i] = doOp(vals, s1, op, s2, target);
            ok += done[i];
        }
        return toBinary(vals, "z");
    };

    cout << toLL(sim(initVals)) << endl;
}

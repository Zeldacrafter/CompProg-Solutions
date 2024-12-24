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

    auto sim = [&](map<string, bool> vals, map<string, string> swap = {}) {
        vector<bool> done(SZ(ops));
        int ok = 0;
        for(int i = 0; ok < SZ(done); i = (i + 1) % SZ(ops)) {
            if(done[i]) continue;
            auto [s1, op, s2, target] = ops[i];
            if(swap.count(target)) target = swap[target];
            done[i] = doOp(vals, s1, op, s2, target);
            ok += done[i];
        }
        return toBinary(vals, "z");
    };

    cout << "Initial: " << endl
         << " " << toBinary(initVals, "x") << endl
         << "+" << toBinary(initVals, "y") << endl
         << sim(initVals) << endl << endl;


    map<string, string> swap;
    swap["qjj"] = "gjc";
    swap["gjc"] = "qjj";

    swap["wmp"] = "z17";
    swap["z17"] = "wmp";

    swap["z26"] = "gvm";
    swap["gvm"] = "z26";

    swap["z39"] = "qsb";
    swap["qsb"] = "z39";

    cout << "After swapping:" << endl;
    cout << " " << toBinary(initVals, "x") << endl
         << "+" << toBinary(initVals, "y") << endl;
    cout << sim(initVals, swap) << endl << endl;

    if(toLL(toBinary(initVals, "x")) + toLL(toBinary(initVals, "y")) == toLL(sim(initVals, swap))) {
        vector<string> swapTargets;
        for(auto [s, _] : swap) swapTargets.pb(s);
        sort(ALL(swapTargets));
        cout << "Found solution:" << endl
             << pp(swapTargets, ",") << endl;
    } else {
        cout << "Swaps dont work. Trying to detect wrong bits" << endl;

        F0R(i, 45) F0R(j, 45) {
            if(i && j) continue;
            map<string, bool> vals;

            F0R(k, 45) {
                if(i != k) vals[toInp("x", k)] = false;
                if(j != k) vals[toInp("y", k)] = false;
            }
            vals[toInp("x", i)] = true;
            vals[toInp("y", j)] = true;


            string x = toBinary(vals, "x"),
               y = toBinary(vals, "y"),
               res = sim(vals);

            if(toLL(x) + toLL(y) != toLL(res)) {
                cout << "Something is wrong at " << dvar(i, j) << endl
                     << " " << x << endl
                     << "+" << y << endl
                     << res << endl << endl;
            }
        }
    }
}

#include "../template.cc"

void solve() {
    ll res = 0;
    vector<pair<string, int>> ss;
    getInp([&](auto& cin, int) {
            string s;
            int k;
            cin >> s >> k;
            ss.eb(s, k);
    });

    set<int> seen;
    for(int i = 0; !seen.count(i);) {
        seen.insert(i);

        auto [s, k] = ss[i];

        if(s == "nop") {
            i++;
        } else if(s == "acc") {
            res += k;
            i++;
        } else if(s == "jmp") {
            i += k;
        }
    }

    cout << res << endl;
}


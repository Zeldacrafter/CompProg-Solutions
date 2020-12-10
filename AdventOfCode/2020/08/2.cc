#include "../template.cc"

vector<pair<string, int>> ss;
int ok(int x) {
    set<int> seen;
    int res = 0;
    for(int i = 0; i < SZ(ss);) {
        if(seen.count(i))
            return false;
        seen.insert(i);

        auto [s, k] = ss[i];

        if((i != x && s == "nop") || (i == x && s == "jmp")) {
            i++;
        } else if(s == "acc") {
            res += k;
            i++;
        } else if((i != x && s == "jmp") || (i == x && s == "nop")) {
            i += k;
        }
    }
    return res;
}

void solve() {
    getInp([&](auto& cin, int) {
            string s;
            int k;
            cin >> s >> k;
            ss.eb(s, k);
    });

    F0R(i, SZ(ss)) {
        int x = ok(i);
        if(x)
            cout << x << endl;
    }
}


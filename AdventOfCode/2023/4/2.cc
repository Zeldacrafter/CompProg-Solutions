#include "../utils.cc"

void solve() {
    ll res = 0;
    map<int, int> amt;

    getInp([&](auto& cin, int i) {
        res += ++amt[i];

        string num; cin >> num >> num;
        set<int> me, them, both;
        while(cin >> num && num != "|") me.insert(stoi(num));
        while(cin >> num) them.insert(stoi(num));
        set_intersection(ALL(me), ALL(them), inserter(both, both.begin()));

        F0R(j, SZ(both)) amt[i + j + 1] += amt[i];
    });

    cout << res << endl;
}


#include "../utils.cc"

void solve() {
    ll res = 0;

    getInp([&](auto& cin, int) {
        string num; cin >> num >> num;
        set<int> me, them, both;
        while(cin >> num && num != "|") me.insert(stoi(num));
        while(cin >> num) them.insert(stoi(num));
        set_intersection(ALL(me), ALL(them), inserter(both, both.begin()));

        if(SZ(both)) res += 1 << (SZ(both) - 1);
    });

    cout << res << endl;
}


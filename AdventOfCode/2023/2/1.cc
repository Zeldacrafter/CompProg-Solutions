#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        string s, type; int id, amt; 
        cin >> s >> id >> s;

        while(cin >> amt >> type) {
            if(type.back() == ',' || type.back() == ';') type.pop_back();

            if(type == "red" && amt > 12) return;
            if(type == "green" && amt > 13) return;
            if(type == "blue" && amt > 14) return;
        }
        res += id;
    });

    cout << res << endl;
}


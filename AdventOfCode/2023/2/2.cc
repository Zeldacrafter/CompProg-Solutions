#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        string s, type; int id, amt; 
        cin >> s >> id >> s;

        int minR = 0, minB = 0, minG = 0;
        while(cin >> amt >> type) {
            if(type.back() == ',' || type.back() == ';') type.pop_back();

            if(type == "red") ckmax(minR, amt);
            if(type == "green") ckmax(minG, amt);
            if(type == "blue") ckmax(minB, amt);
        }
        res += minR*minG*minB;
    });

    cout << res << endl;
}


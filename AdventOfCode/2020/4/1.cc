#include "../template.cc"

vector<string> need{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
void solve() {
    ll res = 0;
    set<string> s;

    auto check = [&]() {
        bool ok = true;
        for(string x : need)
            ok &= s.count(x);
        if(ok)
            res++;
        s.clear();
    };

    vector<string> ss = getInp([&](auto& cin, int i) {
        char bad;
        string key(3, '?'), val;
        int cnt = 0;
        while(cin >> key[0] >> key[1] >> key[2] >> bad >> val) {
            s.insert(key);
            cnt++;
        } 
        if(!cnt)
            check();
    });
    check();

    cout << res << endl;
}


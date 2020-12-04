#include "../template.cc"

vector<string> need{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
set<string> cols{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

template<typename T>
bool betw(T a, T b, T c) {
    return a >= b && a <= c;
}

void solve() {
    ll res = 0;
    set<string> keys;

    string toCheck;
    bool ok = true;
    auto check = [&]() {
        for (string x : need) ok &= keys.count(x);
        if (ok)
            res++;
        keys.clear();
        ok = true;
    };

    vector<string> ss = getInp([&](auto& cin, int) {
        char bad;
        string key(3, '?');
        int cnt = 0;
        while (cin >> key[0] >> key[1] >> key[2] >> bad) {
            string s;
            cin >> s;
            stringstream cinS(s);
            if (key == "byr") {
                int val;
                cinS >> val;
                ok &= betw(val, 1920, 2002);
            } else if (key == "iyr") {
                int val;
                cinS >> val;
                ok &= betw(val, 2010, 2020);
            } else if (key == "eyr") {
                int val;
                cinS >> val;
                ok &= betw(val, 2020, 2030);
            } else if (key == "hgt") {
                int h;
                string iden;

                ok &= cinS >> h >> iden && SZ(iden) == 2 && 
                       ((iden == "cm" && betw(h, 150, 193)) || 
                        (iden == "in" && betw(h, 50, 76)));
            } else if (key == "hcl") {
                ok &= SZ(s) == 7 && s[0] == '#'
                    && all_of(1 + ALL(s), [](char c) { return betw(c, '0', '9') || betw(c, 'a', 'f'); } );
            } else if (key == "ecl") {
                ok &= cols.count(s);
            } else if (key == "pid") {
                ok &= SZ(s) == 9 && all_of(ALL(s), [](char c) { return betw(c, '0', '9'); });
            }
            keys.insert(key);
            cnt++;
        }

        if (!cnt)
            check();
    });
    check();

    cout << res << endl;
}


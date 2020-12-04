#include "../template.cc"

template <typename T>
bool in(T lb, T n, T hb) {
    return lb <= n && n <= hb;
}

int sstoi(const string& s) {
    try {
        return stoi(s);
    } catch (const exception&) {
        dout << "Could not parse " << s << endl;
        return -1337;
    }
}

struct Passports : vector<map<string, string>> {
    Passports(vector<string> ss, char itemSep = ':') {
        parseAll(ss, itemSep);
    }

    void parseAll(vector<string> ss, char itemSep) {
        map<string, string> curr;
        
        for(string& s : ss) {
            if(s == "") {
                push_back(curr);
                curr = map<string, string>();
                continue;
            }
            stringstream cin(s);
            while(cin.peek() != EOF) {
                string key, value;
                char sep;

                while(cin.peek() == ' ') cin.get();
                while(cin.peek() != itemSep) key.pb(cin.get()); 
                cin >> sep >> value;
                curr[key] = value;
            }
        }
        if(!curr.empty())
            push_back(curr);
    }
};

map<string, function<bool(const string&)>> checks{
    {"byr",
     [](const string& s) -> bool {
         if (SZ(s) != 4) return false;
         return in(1920, sstoi(s), 2002);
     }},
    {"iyr",
     [](const string& s) -> bool {
         if (SZ(s) != 4) return false;
         return in(2010, sstoi(s), 2020);
     }},
    {"eyr",
     [](const string& s) -> bool {
         return SZ(s) == 4 && in(2020, sstoi(s), 2030);
     }},
    {"hgt",
     [](const string& s) -> bool {
         if (SZ(s) < 3) return false;
         int height = sstoi(s.substr(0, SZ(s) - 2));
         string type = s.substr(SZ(s) - 2, 2);
         return (type == "cm" && in(150, height, 193)) ||
                (type == "in" && in(50, height, 76));
     }},
    {"hcl",
     [](const string& s) -> bool {
         return SZ(s) == 7 && s[0] == '#' &&
                all_of(1 + ALL(s),
                       [](char c) { return isdigit(c) || in('a', c, 'f'); });
     }},
    {"ecl",
     [](const string& s) -> bool {
         static set<string> colors{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
         return colors.count(s);
     }},
    {"pid", [](const string& s) -> bool {
         return SZ(s) == 9 && all_of(ALL(s), [](char c) { return isdigit(c); });
     }}
};

void a() {
    Passports ps(getInp());

    cout << count_if(ALL(ps), 
        [](const auto& m) {
            int cnt = 0;
            for (const auto& [k, v] : m) 
                cnt += checks.count(k);
            return cnt == SZ(checks);
        }) << endl;
    cout << count_if(ALL(ps), [](const auto& m) {
        int cnt = 0;
        for (const auto& [k, v] : m) 
            cnt += checks.count(k) && checks[k](v);
        return cnt == SZ(checks);
    }) << endl;
}


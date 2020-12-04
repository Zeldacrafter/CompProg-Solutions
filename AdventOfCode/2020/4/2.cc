#include "passport.hh"

map<string, function<int(const string&)>> checks{
    {"byr",
     [](const string& s) -> bool {
         return SZ(s) == 4 && in(1920, sstoi(s), 2002);
     }},
    {"iyr",
     [](const string& s) -> bool {
         return SZ(s) == 4 && in(2010, sstoi(s), 2020);
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
    {"pid", 
     [](const string& s) -> bool {
         return SZ(s) == 9 && all_of(ALL(s), [](char c) { return isdigit(c); });
     }}
};

void solve() {
    Passports ps(getInp());

    cout << ps.countValid(checks) << endl;
}


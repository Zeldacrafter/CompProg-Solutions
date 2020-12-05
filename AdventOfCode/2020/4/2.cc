#include "passport.hh"

map<string, function<ll(const string&)>> checks{
    {"byr",
     [](auto& s) {
         return SZ(s) == 4 && in(1920, sstoi(s), 2002);
     }},
    {"iyr",
     [](auto& s) {
         return SZ(s) == 4 && in(2010, sstoi(s), 2020);
     }},
    {"eyr",
     [](auto& s) {
         return SZ(s) == 4 && in(2020, sstoi(s), 2030);
     }},
    {"hgt",
     [](auto& s) {
         if (SZ(s) < 3) return false;
         int height = sstoi(s.substr(0, SZ(s) - 2));
         string type = s.substr(SZ(s) - 2, 2);
         return (type == "cm" && in(150, height, 193)) ||
                (type == "in" && in(50, height, 76));
     }},
    {"hcl",
     [](auto& s) {
         return SZ(s) == 7 && s[0] == '#' &&
                all_of(1 + ALL(s),
                       [](char c) { return isdigit(c) || in('a', c, 'f'); });
     }},
    {"ecl",
     [](auto& s) {
         static set<string> colors{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
         return colors.count(s);
     }},
    {"pid", 
     [](auto& s) {
         return SZ(s) == 9 && all_of(ALL(s), [](char c) { return isdigit(c); });
     }}
};

void solve() {
    Passports ps(getInp());

    cout << count_if(ALL(ps), [&](const auto& m) {
                return Passports::getScore(m, checks) == SZ(checks);
            }) << endl;
}


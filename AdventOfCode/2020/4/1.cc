#include "passport.hh"

bool constTrue(const string&) { return true; }

map<string, function<ll(const string&)>> checks{
    {"byr", constTrue },
    {"iyr", constTrue },
    {"eyr", constTrue },
    {"hgt", constTrue },
    {"hcl", constTrue },
    {"ecl", constTrue },
    {"pid", constTrue }
};

void solve() {
    Passports ps(getInp());

    cout << count_if(ALL(ps), [&](const auto& m) {
                return Passports::getScore(m, checks) == SZ(checks);
            }) << endl;
}


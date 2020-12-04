#include "passport.hh"

bool constTrue(const string&) { return true; }

map<string, function<int(const string&)>> checks{
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

    cout << ps.countValid(checks) << endl;
}


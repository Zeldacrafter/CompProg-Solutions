#include "passport.hh"

void solve() {
    Passports ps(getInp());

    cout << count_if(ALL(ps), 
        [](const auto& m) {
            int cnt = 0;
            for (const auto& [k, v] : m) 
                cnt += checks.count(k);
            return cnt == SZ(checks);
        }) << endl;
}


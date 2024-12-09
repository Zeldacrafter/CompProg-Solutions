#include "../utils.cc"

void solve() {
    string s = getInp()[0];

    list<pair<int, int>> a;
    int cnt = 0;
    F0R(i, SZ(s)) {
        if(i & 1) a.emplace_back(-1, s[i] - '0');
        else a.emplace_back(cnt++, s[i] - '0');
    }

    auto itFile = prev(a.end());
    while(itFile != a.begin()) {

        bool ok = false;
        auto itSpace = a.begin();
        while(!ok && itSpace != itFile) {
            if(itSpace->fi != -1) ++itSpace;

            if(itSpace->se < itFile->se) {
                ++itSpace;
            } else {
                auto [id, amt] = *itFile;                

                a.emplace(itSpace, -1, 0);
                a.emplace(itSpace, id, amt);
                *itSpace = mp(-1, itSpace->se - amt);

                if(next(itFile) != a.end()) 
                    *next(itFile) = mp(-1, next(itFile)->se + itFile->se + prev(itFile)->se);
                --itFile; --itFile;
                a.erase(next(itFile));
                a.erase(next(itFile));

                ok = true;
            }
        }
        if(!ok) {
            --itFile; --itFile;
        }
    }

    ll res = 0, pos = 0;
    for(auto [id, amt] : a) {
        if(id == -1) pos += amt;
        else F0R(i, amt) res += id * pos++;
    }
    cout << res << endl;
}


#include "../utils.cc"

void solve() {
    string s = getInp()[0];

    list<pair<int, int>> a;
    int cnt = 0;
    F0R(i, SZ(s)) {
        if(i & 1) a.emplace_back(-1, s[i] - '0');
        else a.emplace_back(cnt++, s[i] - '0');
    }

    for(auto it = a.begin(); it != a.end(); ++it) {
        while(it->fi != -1) ++it;
        if(it == prev(a.end())) break;

        while(it != prev(a.end()) && it->se) {
            while(a.back().fi == -1) a.pop_back(); 
            if(it == prev(a.end())) break;

            auto [id, old_back] = a.back();
            int amt = min( old_back, it->se );

            a.emplace(it, -1, 0);
            a.emplace(it, id, amt);
            *it = mp(-1, it->se - amt);

            a.pop_back();
            if(old_back > amt) a.emplace_back(id, old_back - amt);
        }
    }

    ll res = 0, pos = 0;
    for(auto [id, amt] : a) {
        if(id == -1) continue;
        F0R(i, amt) res += id * pos++;
    }
    
    cout << res << endl;
}


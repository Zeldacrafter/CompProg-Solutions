#include "../utils.cc"

int getHash(string s) {
    int val = 0;
    for(char c : s) val = (val + c) * 17 % 256;
    return val;
}

void solve() {
    vector<string> ss = split(getInp()[0], ",");

    vector<vector<pair<string, int>>> boxes(256);
    for(string& s : ss) {
        string key = s.substr(0, SZ(s) - 1 - isdigit(s.back()));
        auto& box = boxes[getHash(key)];
        auto it = find_if(ALL(box), [&](auto& p) { return p.fi == key; });
        if(isdigit(s.back()) && it == box.end())
            box.eb(key, s.back() - '0');
        else if(isdigit(s.back()) && it != box.end())
            *it = mp(key, s.back() - '0');
        else if(!isdigit(s.back()) && it != box.end())
            box.erase(it);
    }

    ll res = 0;
    F0R(i, SZ(boxes)) F0R(j, SZ(boxes[i]))
        res += (i + 1)*(j + 1)*boxes[i][j].se;
    cout << res << endl;
}

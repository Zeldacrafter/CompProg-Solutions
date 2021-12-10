#include "../utils.cc"

map<char, char> match = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
map<char, int> score = {{'(', 1}, {'[', 2}, {'{', 3}, {'<', 4}};

void solve() {
    vector<ll> res;
    getInp([&](auto& cin, int) {
        string str; cin >> str;

        stack<char> s;
        bool ok = true;
        for (char c : str) {
            if(match.count(c))
                s.push(c);
            else {
                ok &= match[s.top()] == c;
                if(!ok) return;
                s.pop();
            }
        }

        ll r = 0;
        for(; SZ(s); s.pop()) r = r*5 + score[s.top()];
        res.pb(r);
    });
    sort(ALL(res));

    cout << res[SZ(res)/2] << endl;
}


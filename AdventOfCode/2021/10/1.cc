#include "../utils.cc"

map<char, char> match = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
map<char, int> score = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};

void solve() {
    ll res = 0;
    getInp([&](auto& cin, int) {
        string str; cin >> str;
        stack<char> s;
        for (char c : str) {
            if(match.count(c))
                s.push(c);
            else {
                if(match[s.top()] != c) {
                    res += score[c];
                    return;
                }
                s.pop();
            }
        }
    });

    cout << res << endl;
}


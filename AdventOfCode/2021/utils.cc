#pragma once
#include "/home/al/git/CompProg/code/template_long.cc"
///////////////////////////////////////////////////////////////
// Reading input line by line
///////////////////////////////////////////////////////////////

template<typename F>
vector<string> getInp(F f) {
    vector<string> res;
    string s;
    for (int i = 0; getline(cin, s); ++i, res.pb(s)) {
        stringstream inp(s);
        f(inp, i);
    }
    return res;
}

vector<string> getInp() {
    return getInp([](stringstream&, int) {});
}

vector<string> split(const string& s, const string& delim) {
    vector<string> res;
    size_t last = 0, next = 0;
    while((next = s.find(delim, last)) != string::npos) {
        res.pb(s.substr(last, next - last));
        last = next + SZ(delim);
    }
    res.pb(s.substr(last));
    return res;
}

pair<string, string> splitP(const string& s, const string& delim) {
    vector<string> ss = split(s, delim);
    static bool didError = false;
    if(SZ(ss) != 2 && !didError) {
        dout << "Warning: \"" << s << "\" split with delim \"" << delim << "\" prodces " << ss << endl;
        didError = true;
    }
    return mp(ss[0], ss[1]);
}

///////////////////////////////////////////////////////////////
// Begin Solution
///////////////////////////////////////////////////////////////

void solve();

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}

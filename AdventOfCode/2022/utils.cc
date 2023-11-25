#pragma once
#include "/home/alexp/git/CompProg/code/utils/ops.cc"

///////////////////////////////////////////////////////////////
// https://github.com/Zeldacrafter/CompProg/blob/master/code/utils/y_combinator.cc

// for c++14 and above;  explicitly specify the return type of the lambda
// links:
//  1. https://stackoverflow.com/a/40873657
//  2. http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<typename F>
struct y_combinator_result {
  F f;
  template<typename T>
  explicit y_combinator_result(T&& fun) : f(forward<T>(fun)) {}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return f(ref(*this), forward<Args>(args)...);
  }
};
template<typename F>
decltype(auto) y_combinator(F&& f) {
  return y_combinator_result<decay_t<F>>(forward<F>(f));
}

///////////////////////////////////////////////////////////////
// Reading input line by line
///////////////////////////////////////////////////////////////

template<typename F>
vector<string> getInp(F f, string regexPattern = "") {
    
    vector<string> res;
    string s;
    int emptyLineCounter = 0;
    for (int i = 0; getline(cin, s); ++i, res.pb(s)) {
        if (s == "") emptyLineCounter++;

        // Match regex is exists:
        if(regexPattern != "") {
          regex re(regexPattern);

          smatch match;
          if(regex_search(s, match, re)) {
            string resS = "";
            for (auto submatch : match) {
              if (string(submatch) != s) {
                if(resS != "") resS += " ";
                resS += submatch;
              }
            }
            s = resS;
          } else {
            dout << "Input line \"" << s << "\" does not match regex string!" << endl;
          }
        }
        stringstream inp(s);
        f(inp, i);
    }
    if (emptyLineCounter)
        dout << "Number of empty lines: " << emptyLineCounter << endl;
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

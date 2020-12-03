#include "../template.cc"

void solve() {
    vector<string> ss = getInp();

    auto calc = [&](int amt) {
        int res = 0;
        for(string& s : ss)
            for(char c = 'a'; c <= 'z'; ++c)
                if(count(ALL(s), c) == amt) {
                    res++;
                    break;
                }
        return res;
    };

    cout << calc(3)*calc(2) << endl;
}


#include "../utils.cc"

vector<string> stacks = {
    "DBJV",
    "PVBWRDF",
    "RGFLDCWQ",
    "WJPMLNDB",
    "HNBPCSQ",
    "RDBSNG",
    "ZBPMQFSH",
    "WLF",
    "SVFMR"
};

void solve() {

    getInp([&](auto& cin, int i) {
        if (i <= 9) return;

        string s; int amt, from, to;
        cin >> s >> amt >> s >> from >> s >> to;
        from--; to--;

        stacks[to].insert(stacks[to].end(), SZ(stacks[from]) - amt + ALL(stacks[from]));
        stacks[from].resize(SZ(stacks[from]) - amt);
    });

    for(string& s : stacks) cout << s.back();
}


#include "../template.cc"

template <typename T>
bool in(T lb, T n, T hb) {
    return lb <= n && n <= hb;
}

int sstoi(const string& s) {
    try {
        return stoi(s);
    } catch (const exception&) {
        dout << "Could not parse " << s << endl;
        return -1337;
    }
}

struct Passports : vector<map<string, string>> {
    Passports(vector<string> ss, string itemSep = ":") {
        parseAll(ss, itemSep);
    }

    void parseAll(vector<string> ss, string itemSep) {
        map<string, string> curr;
        
        for(string& s : ss) {
            if(s == "") {
                push_back(curr);
                curr = map<string, string>();
            } else {
                vector<string> tokens = split(s, " ");
                for(string& token : tokens) {
                    auto [k, v] = splitP(token, itemSep);
                    curr[k] = v;
                }
            }
        }
        if(!curr.empty())
            push_back(curr);
    }

    void removeNonMatching(map<string, function<ll(const string&)>> checks, ll neededScore) {
        erase(
            remove_if(ALL(*this), 
                [&](const auto& pp) { return Passports::getScore(pp, checks) < neededScore; }
            ), 
            end()
        );
    }

    static ll getScore(map<string, string> passport, map<string, function<ll(const string&)>> checks) {
        ll cnt = 0;
        for(const auto& [k, v] : passport)
            if(checks.count(k))
                cnt += checks[k](v);
        return cnt;
    }
};

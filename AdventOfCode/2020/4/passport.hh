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
    Passports(vector<string> ss, char itemSep = ':') {
        parseAll(ss, itemSep);
    }

    void parseAll(vector<string> ss, char itemSep) {
        map<string, string> curr;
        
        for(string& s : ss) {
            if(s == "") {
                push_back(curr);
                curr = map<string, string>();
                continue;
            }
            stringstream cin(s);
            while(cin.peek() != EOF) {
                string key, value;
                char sep;

                while(cin.peek() == ' ') cin.get();
                while(cin.peek() != itemSep) key.pb(cin.get()); 
                cin >> sep >> value;
                curr[key] = value;
            }
        }
        if(!curr.empty())
            push_back(curr);
    }

    static ll getScore(map<string, string> passport, map<string, function<ll(const string&)>> checks) {
        ll cnt = 0;
        for(const auto& [k, v] : passport)
            if(checks.count(k))
                cnt += checks[k](v);
        return cnt;
    }

    
};

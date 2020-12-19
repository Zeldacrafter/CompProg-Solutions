#include "../template.cc"

typedef vector<vvi> vvvi;

const int MAXN = 200;

map<int, char> val;
vvvi adj(MAXN);

pair<bool, vi> valid(string& s, int node = 0, int pos = 0) {
    if(pos >= SZ(s))
        return mp(false, vi());

    if(!SZ(adj[node])) {
        assert(val.count(node));
        return mp(s[pos] == val[node], vi{pos + 1});
    }

    vi res;
    for(vi& adjPoss : adj[node]) {
        vi inds{pos}; // all possible indexes where i end up 

        for(int nextNode : adjPoss) {
            vi newInds; // all indexes where i end up after processing nextNode

            for(int p : inds) {
                auto [ok, newInds2] = valid(s, nextNode, p);
                if(ok) newInds.insert(newInds.end(), ALL(newInds2));
            }

            inds = newInds;
        }
        res.insert(res.end(), ALL(inds));
    }
    return mp(SZ(res), res);
}

void solve() {

    vector<string> toCheck;
    bool part2 = false;

    vector<string> ss = getInp([&](auto& cin, int) {
        if(!part2) {
            int x;
            char c;
            if(!(cin >> x >> c >> ws)) {
                part2 = true;
                return;
            }
            if(cin.peek() == '"') {
                cin >> c >> c;
                val[x] = c;
            } else {
                string s;
                getline(cin, s);
                
                vector<string> ss = split(s, "|");
                for(string& curr : ss) {
                    stringstream inp(curr);
                    adj[x].eb();
                    int val;
                    while(inp >> val)
                        adj[x].back().pb(val);
                }
            }
        } else {
            string s;
            cin >> s;
            toCheck.pb(s);
        }
    });

    adj[8].pb(vi{42, 8});
    adj[11].pb(vi{42, 11, 31});

    ll res = 0;
    for(string& s : toCheck) {
        auto [ok, poss] = valid(s);
        res += ok && any_of(ALL(poss), [&](int x) {return x == SZ(s); });
    }
    cout << res << endl;
}


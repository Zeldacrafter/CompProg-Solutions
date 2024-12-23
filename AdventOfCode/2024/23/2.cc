#include "../utils.cc"

bool getClique(const vector<vector<bool>>& mat, int size, vi& clique, int i = 0) {
    if(SZ(clique) == size) return true;
    if(i + (size - SZ(clique)) >= SZ(mat)) return false;

    FOR(j, i, SZ(mat) - (size - SZ(clique)) + 1) {
        bool ok = true;
        for(int x : clique) ok &= mat[x][j];
        if(!ok) continue;

        clique.pb(j);
        if(getClique(mat, size, clique, j + 1)) return true;
        clique.pop_back();
    }
    return false;
}


void solve() {
    map<int, set<int>> adj;
    map<string, int> toInd;
    map<int, string> fromInd;

    getInp([&](auto& cin, int) {
        string s; cin >> s;
        auto [a, b] = splitP(s, "-");
        if(!toInd.count(a)) {
            toInd[a] = SZ(toInd);
            fromInd[SZ(fromInd)] = a;
        }
        if(!toInd.count(b)) {
            toInd[b] = SZ(toInd);
            fromInd[SZ(fromInd)] = b;
        }
        adj[toInd[b]].insert(toInd[a]);
        adj[toInd[a]].insert(toInd[b]);
    });

    vector<vector<bool>> mat(SZ(toInd), vector<bool>(SZ(toInd), false));
    for(auto& [_, i] : toInd)
        for(auto& j : adj[i]) 
            mat[i][j] = true;

    vi bestClique;
    for(int size = 1; ; ++size) {
        vi clique;
        if(!getClique(mat, size, clique)) break;
        bestClique = clique;
    }

    vector<string> res;
    for(int i : bestClique) res.pb(fromInd[i]);
    sort(ALL(res));
    cout << pp(res, ",") << endl;
}


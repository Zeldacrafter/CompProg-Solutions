#include "../utils.cc"

vii dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<ii, char> 
    dirToChar = { {mp(1, 0), 'v'}, {mp(-1, 0), '^'}, {mp(0, 1), '>'}, {mp(0, -1), '<'} }, 
    keyPadPosToChar = { {mp(0, 0), '7'}, {mp(0, 1), '8'}, {mp(0, 2), '9'}, {mp(1, 0), '4'}, {mp(1, 1), '5'}, {mp(1, 2), '6'}, {mp(2, 0), '1'}, {mp(2, 1), '2'}, {mp(2, 2), '3'}, {mp(3, 1), '0'}, {mp(3, 2), 'A'} },
    dirPadPosToChar = { {mp(0, 1), '^'}, {mp(0, 2), 'A'}, {mp(1, 0), '<'}, {mp(1, 1), 'v'}, {mp(1, 2), '>'} };
map<char, ii> keyPadCharToPos, dirPadCharToPos;

vector<string> getMoves(ii end, ii start, map<ii, vii>& prevs) {
    if(start == end) return vector<string>{""};

    vector<string> res;
    for(ii dir : prevs[end]) {
        vector<string> currRes = getMoves(end - dir, start, prevs);
        for(string& s : currRes) res.pb(s + dirToChar[dir]);
    }
    return res;
}

vector<string> bestMoves(ii start, ii end, map<ii, char>& coords) {
    map<ii, vii> prevs;
    map<ii, int> dist;
    dist[start] = 0;

    queue<ii> q;
    q.push(start);
    while(SZ(q)) {
        ii curr = q.front(); q.pop();
        if(dist.count(end) && dist[curr] > dist[end]) break;

        F0R(i, 4) {
            ii p = curr + dirs[i];
            if(!coords.count(p) || (dist.count(p) && dist[p] < dist[curr] + 1)) continue;
            q.push(p);
            prevs[p].pb(dirs[i]);
            dist[p] = dist[curr] + 1;
        }
    }

    vector<string> moves = getMoves(end, start, prevs);
    for(string& m : moves) m += "A";
    return moves;
}

ll cntSols(string& s, int indirs, bool firstDepth = true) {
    static map<tuple<string, int>, ll> dp;
    if(dp.count(mp(s, indirs))) return dp[mp(s, indirs)];

    ii currP = firstDepth ? mp(3, 2) : mp(0, 2);
    map<ii, char> posToChar = firstDepth ? keyPadPosToChar : dirPadPosToChar;
    map<char, ii> charToPos = firstDepth ? keyPadCharToPos : dirPadCharToPos;  

    ll res = 0;
    for (char c : s) {
        vector<string> moves = bestMoves(currP, charToPos[c], posToChar);
        if(!indirs) {
            res += SZ(moves[0]);
        } else {
            ll mn = 1e18;
            for(string& m : moves) ckmin(mn, cntSols(m, indirs - 1, false));
            res += mn;
        }
        currP = charToPos[c];
    }

    return dp[mp(s, indirs)] = res;
}

void solve() {
    for(auto& [k, v] : keyPadPosToChar) keyPadCharToPos[v] = k;
    for(auto& [k, v] : dirPadPosToChar) dirPadCharToPos[v] = k;

    vector<string> ss = getInp();

    ll res = 0;
    for(string s : ss)
        res += stoll(s.substr(0, SZ(s) - 1)) * cntSols(s, 25);
    cout << res << endl;
}


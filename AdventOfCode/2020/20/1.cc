#include "../template.cc"

const int MAXN = 10;
const ii INVALID = mp(-100, -100);

ii getDir(const vector<string>& a, const vector<string>& b) {
    if(a[0] == b.back())
        return mp(0, -1);

    if(a.back() == b[0])
        return mp(0, 1);

    bool ok = true;
    F0R(i, SZ(a))
        ok &= a[i][0] == b[i].back();
    if(ok)
        return mp(-1, 0);

    ok = true;
    F0R(i, SZ(a))
        ok &= a[i].back() == b[i][0];
    if(ok)
        return mp(1, 0);

    return INVALID;
}

void flipY(vector<string>& a) {
    reverse(ALL(a));
}

void flipX(vector<string>& a) {
    F0R(i, SZ(a))
        reverse(ALL(a[i]));
}

void cyclicRoll(char &a, char &b, char &c, char &d) {
    char temp = a;
    a = b;
    b = c;
    c = d;
    d = temp;
}

void rot90(vector<string>& a) {
    int n = SZ(a);
    F0R(i, n/2)
        F0R(j, (n+1)/2)
            cyclicRoll(a[i][j], a[n-1-j][i], a[n-1-i][n-1-j], a[j][n-1-i]);
}

ii tryMove(vector<string>& a, vector<string>& b) {
    F0R(i, 4) {
        F0R(j, 2) {
            F0R(k, 2) {
                ii dir = getDir(a, b);
                if(dir != INVALID)
                    return dir;

                flipY(b);
            }
            flipX(b);
        }
        rot90(b);
    }

    return INVALID;
}

void solve() {
    // Input parsing
    vector<vector<string>> a;
    map<int, int> indToId;
    vector<string> ss = getInp([&](auto& cin, int) {
        string s;
        if(cin.peek() == 'T') {
            int x;
            cin >> s >> x;
            indToId[SZ(a)] = x;
            a.eb();
        } else {
            getline(cin, s);
            if(s == "") return;
            a.back().pb(s);
        }
    });
    int n = SZ(a);

    // BFS for building grid adjacencies
    map<int, ii> toPos;
    map<ii, int> fromPos;
    set<int> seen;
    queue<int> q;

    q.push(0);
    toPos[0] = mp(0, 0);
    fromPos[mp(0, 0)] = 0;
    while(SZ(q)) {
        int curr = q.front();
        q.pop();

        F0R(i, n) if(!seen.count(i)) {
            ii move = tryMove(a[curr], a[i]);
            if(move == INVALID)
                continue;

            seen.insert(i);
            q.push(i);
            toPos[i] = toPos[curr] + move;
            fromPos[toPos[curr] + move] = i;
        }
    }

    // Get bounding box
    int maxX = 0, minX = 0, maxY = 0, minY = 0;
    for(auto [k, v] : toPos) {
        ckmax(maxX, v.fi);
        ckmax(maxY, v.se);
        ckmin(minX, v.fi);
        ckmin(minY, v.se);
    }

    ll res = 1;
    for(int i : {minX, maxX})
        for(int j : {minY, maxY})
            res *= indToId[fromPos[mp(i, j)]];
    cout << res << endl;
}



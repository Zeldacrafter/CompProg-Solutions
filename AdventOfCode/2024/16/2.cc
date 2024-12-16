#include "../utils.cc"

vii dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void solve() {
    vector<string> ss = getInp();

    ii start, end;
    F0R(i, SZ(ss)) F0R(j, SZ(ss[0])) {
        if(ss[i][j] == 'S') start = mp(i, j);
        if(ss[i][j] == 'E') end = mp(i, j);
    }

    auto get = [&](ii p) { return ss[p.fi][p.se]; };

    set<tuple<int, ii, int>> q;
    set<pair<ii, int>> seen;
    map<pair<ii, int>, vector<pair<ii, int>>> prevs;
    map<pair<ii, int>, int> best;
    q.emplace(0, start, 0);
    
    int bestScore = -1;
    while(SZ(q)) {
        auto [score, pos, dir] = *q.begin();
        q.erase(q.begin());

        if(~bestScore && score > bestScore) break;
        if(pos == end) bestScore = score;

        if(seen.contains(mp(pos, dir))) continue;
        seen.emplace(pos, dir);


        auto add = [&](int s, ii p, int d) {
            if(best.count(mp(p, d)) && s > best[mp(p, d)]) return;
            best[mp(p, d)] = s;
            prevs[mp(p, d)].eb(pos, dir);
            q.emplace(s, p, d);
        };

        if(get(pos + dirs[dir]) != '#') add(score + 1, pos + dirs[dir], dir);
        add(score + 1000, pos, (dir + 1) % 4);
        add(score + 1000, pos, (dir + 3) % 4);
    }

    set<ii> seenPos;
    seen.clear();
    queue<pair<ii, int>> q2;
    F0R(i, 4) if(SZ(prevs[mp(end, i)])) {
        seenPos.insert(end);
        seen.emplace(end, i);
        q2.emplace(end, i);
    }

    while(SZ(q2)) {
        auto curr = q2.front();
        q2.pop();

        for(auto prev : prevs[curr]) {
            if(!seen.insert(prev).se) continue;
            seenPos.insert(prev.fi);
            q2.push(prev);
        }
    }

    cout << SZ(seenPos) << endl;
}


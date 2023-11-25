#include "../utils.cc"

int produce(int c1, int c2, int c3, int c4, int c5, int c6) {

    // ore, clay, obsidian, geodes, r1, r2, r3, r4, time
    set<array<int, 9>> seen;
    queue<array<int, 9>> q;

    q.push({0, 0, 0, 0, 1, 0, 0, 0, 24});

    int res = 0;
    while(SZ(q)) {
        auto [o, c, ob, g, r1, r2, r3, r4, t] = q.front();
        q.pop();

        ckmax(res, g);
        if(!t) continue;

        int m = max({c1, c2, c3, c5});
        if(r1 > m) r1 = m;
        if(r2 > c4) r2 = c4;
        if(r3 > c6) r3 = c6;
        if(o > t*m - r1*(t-1)) o = t*m - r1*(t-1);
        if(c > t*c4 - r2*(t-1)) c = t*c4 - r2*(t-1);
        if(ob > t*c6 - r3*(t-1)) ob = t*c6 - r3*(t-1);

        array<int, 9> state = {o, c, ob, g, r1, r2, r3, r4, t};
        if(seen.count(state)) continue;
        seen.insert(state);

        assert(o >= 0 && c >= 0 && ob >= 0 && g >= 0);
        q.push({o+r1, c+r2, ob+r3, g+r4, r1, r2, r3, r4, t-1});
        if(o >= c1)
            q.push({o-c1+r1, c+r2, ob+r3, g+r4, r1+1, r2, r3, r4, t-1});
        if(o >= c2)
            q.push({o-c2+r1, c+r2, ob+r3, g+r4, r1, r2+1, r3, r4, t-1});
        if(o >= c3 && c >= c4)
            q.push({o-c3+r1, c-c4+r2, ob+r3, g+r4, r1, r2, r3+1, r4, t-1});
        if(o >= c5 && ob >= c6)
            q.push({o-c5+r1, c+r2, ob-c6+r3, g+r4, r1, r2, r3, r4+1, t-1});

    }
    return res;
}

void solve() {
    int res = 0;

    getInp([&](auto& cin, int i) {
        int c1, c2, c3, c4, c5, c6;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

        res += (i+1)*produce(c1, c2, c3, c4, c5, c6); 
    },
    "Blueprint (?:[0-9]+): Each ore robot costs ([0-9]+) ore. Each clay robot costs ([0-9]+) ore. Each obsidian robot costs ([0-9]+) ore and ([0-9]+) clay. Each geode robot costs ([0-9]+) ore and ([0-9]+) obsidian.");

    cout << res << endl;
}


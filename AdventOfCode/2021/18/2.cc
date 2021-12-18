#include "../utils.cc"

struct Pr {
    int v;
    vector<Pr> lower;

    Pr(int val) : v{val}, lower{} {}
    Pr(Pr x, Pr y) : v{-1}, lower{x, y} {} 
    Pr(string s) : v{-1}, lower{} {
        int pos = 0;
        *this = Pr(s, pos);
        assert(pos == SZ(s));
    }

    Pr minimize() {
        while(tryExplode().fi || trySplit());
        return *this;
    }

    ll magnitude() {
        if(v != -1) 
            return v;
        else 
            return 3*lower[0].magnitude() + 2*lower[1].magnitude();
    }

  private:
    Pr(string s, int& pos) : v{-1}, lower{} {
        if(isdigit(s[pos])) {
            v = 0;
            while(isdigit(s[pos]))
                v = v*10 + (s[pos++] - '0');
        } else {
            lower.pb(Pr(s, ++pos));
            lower.pb(Pr(s, ++pos));
            pos++;
        }
    }

    void addAtEdge(bool right, int val) {
        if(v != -1) v += val;
        else lower[right].addAtEdge(right, val);
    }

    bool trySplit() {
        if(int val = v; val != -1) {
            if(val >= 10) *this = Pr( Pr(val/2), Pr((val+1)/2) );
            return val >= 10;
        }
        return lower[0].trySplit() || lower[1].trySplit();
    }

    pair<bool, ii> tryExplode(int d = 0) {
        if(v != -1) return mp(false, mp(0, 0));
        if(d == 4) {
            int v1 = lower[0].v, v2 = lower[1].v;
            *this = Pr(0);
            return mp(true, mp(v1, v2));
        }

        auto [b1, p1] = lower[0].tryExplode(d + 1);
        if(b1) {
            lower[1].addAtEdge(false, p1.se);
            return mp(true, mp(p1.fi, 0));
        }
        auto [b2, p2] = lower[1].tryExplode(d + 1);
        if(b2) {
            lower[0].addAtEdge(true, p2.fi);
            return mp(true, mp(0, p2.se));
        }
        return mp(false, mp(0, 0));
    }
};

void solve() {
    vector<Pr> inp;
    getInp([&](auto& cin, int) {
        string s; cin >> s;
        inp.eb(Pr(s).minimize());
    });

    ll res = 0;
    F0R(i, SZ(inp)) F0R(j, SZ(inp)) 
        if(i != j)
            ckmax(res, Pr(inp[i], inp[j]).minimize().magnitude());
    cout << res << endl;
}

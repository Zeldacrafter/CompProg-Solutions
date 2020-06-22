#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR((a), 0, (b))

struct ST {
    int n;
    vi value, depth;
    int inline left(int p) { return p << 1; }
    int inline right(int p) { return (p << 1) + 1; }
    int build(const vi& a, int p, int L, int R, int d) {
        depth[p] = d;
        if (L == R) {
            return value[p] = a[L];
        } else {
            if(depth[p] & 1)
                value[p] = build(a, left(p), L, (R + L) / 2, d - 1) | build(a, right(p), (R + L) /2 + 1, R, d - 1);
            else
                value[p] = build(a, left(p), L, (R + L) / 2, d - 1) ^ build(a, right(p), (R + L) /2 + 1, R, d - 1);
            return value[p];
        }
    }

    int set(int p, int L, int R, int i, int j, int val) {
        if (i > R || j < L) return value[p];
        if (L == R) return value[p] = val;
        if(depth[p] & 1)
            value[p] = set(left(p), L, (R + L) / 2, i, j, val) | set(right(p), (R + L) /2 + 1, R, i, j, val);
        else
            value[p] = set(left(p), L, (R + L) / 2, i, j, val) ^ set(right(p), (R + L) /2 + 1, R, i, j, val);
        return value[p];
    }

    ST(int n) : n(n), value(n * 4, 0), depth(n * 4, 0) {}
    ST(const vi& a) : 
            n(SZ(a)), 
            value(SZ(a) * 4), 
            depth(SZ(a) * 4) {
        build(a, 1, 0, n - 1, 31 - __builtin_clz(n));
    }

    int query() {
        return value[1];
    }
    void set(int x, int val) { set(1, 0, n - 1, x, x, val); }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vi a(1 << n);
    F0R(i, 1 << n) cin >> a[i];

    ST st(a);

    while(m--) {
        int p, b;
        cin >> p >> b;
        st.set(p - 1, b);
        cout << st.query() << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}

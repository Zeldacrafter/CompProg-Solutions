#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, (b))
#define CEIL(a, b) ((a) + (b)-1) / (b)
template <class T>
bool ckmin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}
template <class T>
bool ckmax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}
#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
    if (DEBUG) std::cerr
#define dvar(...) " [" << #__VA_ARGS__ ": " << mt(__VA_ARGS__) << "] "
template <typename T>
struct IsC {
    template <typename C>
    static char test(typename C::const_iterator*);
    template <typename C>
    static int test(...);
    static const bool value = sizeof(test<T>(0)) == sizeof(char);
};
template <>
struct IsC<string> {
    static const bool value = false;
};
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream&,
                                                             const C&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);
template <typename... T>
using TS = tuple_size<tuple<T...>>;
template <size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, ostream&>::type operator<<(
    ostream& o, const tuple<T...>& t) {
    return o << ", " << get<idx>(t) << ')';
}
template <size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
    return operator<<<idx + 1>(o << ", " << get<idx>(t), t);
}
template <size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, ostream&>::type operator<<(
    ostream& o, const tuple<T...>& t) {
    return operator<<<idx + 1>(o << '(' << get<idx>(t), t);
}
template <typename T>
ostream& operator<<(ostream& o, const tuple<T>& t) {
    return o << get<0>(t);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
    return o << mt(p.fi, p.se);
}
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream& o,
                                                             const C& c) {
    o << '[';
    for (auto it = c.cbegin(); it != c.cend(); ++it)
        o << *it << (next(it) != c.cend() ? ", " : "");
    return o << ']';
}
template <typename T>
void tprint(vector<vector<T>>& v, size_t width = 0, ostream& o = cerr) {
    if (!DEBUG) return;
    for (auto& vv : v) {
        for (auto& i : vv) o << setw(width) << i;
        o << endl;
    }
}

struct mod {
    static const ll p = 998244353;
    ll val;
    mod() : val(0) {}
    mod(ll val) : val(val % p) {
        if (this->val < 0) this->val += p;
    }
    mod& operator+=(mod o) {
        val = (val + o.val) % p;
        return *this;
    }
    mod& operator-=(mod o) {
        val = (val - o.val + p) % p;
        return *this;
    }
    mod& operator*=(mod o) {
        val = val * o.val % p;
        return *this;
    }
    mod& operator/=(mod o) { return (*this) *= pow(o, p - 2); }
    mod& operator++() { return (*this) += 1; }
    mod operator++(int) { return ++(*this) - 1; }
    mod& operator--() { return (*this) -= 1; }
    mod operator--(int) { return --(*this) + 1; }
    mod friend operator+(mod a, mod b) { return a += b; }
    mod friend operator-(mod a, mod b) { return a -= b; }
    mod friend operator*(mod a, mod b) { return a *= b; }
    mod friend operator/(mod a, mod b) { return a /= b; }
    static mod pow(mod a, mod b) {
        mod res = 1;
        for (; b.val; b.val >>= 1, a = a * a)
            if (b.val & 1) res = res * a;
        return res;
    }
    friend istream& operator>>(istream& i, mod& m) {
        i >> m.val;
        m.val %= p;
        if (m.val < 0) m.val += p;
        return i;
    }
    friend ostream& operator<<(ostream& o, mod m) { return o << m.val; }
};

struct ST {
    using T = mod;
    const T unit = 0;

    T merge(T l, T r) { return l + r; };

    int n, h;
    vector<pair<mod, mod>> d;
    vector<T> data;
    ST(int n) : n(n), h(31 - __builtin_clz(n)), data(2 * n), d(n, mp(1, 0)) {}
    ST(vector<T>& v) : n(SZ(v)), data(2 * SZ(v)), d(n, mp(1, 0)) {
        copy(ALL(v), data.begin() + SZ(v));
        build();
    }

    void apply(int p, pair<mod, mod> val, int k) {
        data[p] = data[p]*val.fi + val.se*k;
        if(p < n) d[p] = mp(d[p].fi*val.fi, val.fi*d[p].se + val.se);
    }

    void push(int p) {
        for(int s = h, k = 1 << (h - 1); s; --s, k >>= 1) {
            int i = p >> s;
            apply(i << 1, d[i], k);
            apply(i << 1 | 1, d[i], k);
            d[i] = mp(1, 0);
        }
    }

    void updPar(int p) {
        for(int k = 2; p > 1; k <<= 1) {
            p >>= 1;
            data[p] = d[p].fi*(data[p << 1] + data[p << 1 | 1]) + d[p].se*k;
        }
    }

    void build() {
        for (int i = n - 1; i; --i)
            data[i] = merge(data[i << 1], data[i << 1 | 1]);
    }

    T query(int l, int r) {
        l += n, r += n;
        push(l);
        push(r - 1);
        T li = unit, ri = unit;
        for (; l < r; r >>= 1, l >>= 1) {
            if (l & 1) li = merge(li, data[l++]);
            if (r & 1) ri = merge(data[--r], ri);
        }
        return merge(li, ri);
    }

    void update(int l, int r, pair<mod, mod> val) {
        l += n, r += n;
        push(l);
        push(r - 1);
        int l0 = l, r0 = r;
        for (int k = 1; l < r; r >>= 1, l >>= 1, k <<= 1) {
            if (l & 1) apply(l++, val, k);
            if (r & 1) apply(--r, val, k);
        }
        updPar(l0);
        updPar(r0 - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    ST st(n);
    F0R(i, n) cin >> st.data[i + n];
    st.build();

    dout << dvar(st.data) << endl << dvar(st.d) << endl << endl;
    while(q--) {
        int con, l, r;
        cin >> con >> l >> r;

        if(con)
            cout << st.query(l, r) << endl;
        else {
            int a, b;
            cin >> a >> b;
            st.update(l, r, mp(a, b));
        }
        dout << dvar(st.data) << endl << dvar(st.d) << endl;
    }

    return 0;
}


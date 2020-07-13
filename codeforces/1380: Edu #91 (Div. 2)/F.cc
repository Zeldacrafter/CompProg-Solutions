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
#define F0R(a, b) FOR (a, 0, (b))
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
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream&, const C&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);
template <typename... T> using TS = tuple_size<tuple<T...>>;
template<size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return o << ", " << get<idx>(t) << ')';
}
template<size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << ", " << get<idx>(t), t);
}
template<size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << '(' << get<idx>(t), t);
}
template<typename T>
ostream& operator<<(ostream& o, const tuple<T>& t) {
  return o << get<0>(t);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
  return o << mt(p.fi, p.se);
}
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(
    ostream& o, const C& c) {
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
  mod(ll val) : val(val % p) { if (this->val < 0) this->val += p; }
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
    m.val %= mod::p;
    if (m.val < 0) m.val += mod::p;
    return i;
  }
  friend ostream& operator<<(ostream& o, mod m) { return o << m.val; }
};

mod dp[100];

struct node {
    mod withXX, withLX, withXR, withLR;
    int l, r;
};

node getSingle(int d) {
    node res;

    res.l = res.r = d;
    res.withXX = 0;
    res.withLX = !!d;
    res.withXR = 1;
    res.withLR = dp[d];

    return res;
}

struct ST {
    using T = node;
    const T unit = {0, 0, 0, 0, -1, -1};
    T merge(T l, T r) {
        if(l.l == -1)
            return r;
        if(r.l == -1)
            return l;

        node res;
        res.l = l.l;
        res.r = r.r;

        mod p = dp[10*l.r + r.l];

        res.withLR = l.withLR*r.withLR + l.withLX*r.withXR*p;
        res.withXR = l.withXR*r.withLR + l.withXX*r.withXR*p;
        res.withLX = l.withLR*r.withLX + l.withLX*r.withXX*p;
        res.withXX = l.withXR*r.withLX + l.withXX*r.withXX*p;

        return res;
    };
    int n;
    vector<T> data;
    ST(int n) : n(n), data(2 * n) {}
    ST(vector<T>& v) : n(SZ(v)), data(2 * SZ(v)) {
        copy(ALL(v), data.begin() + SZ(v));
        build();
    }
    void build() {
        for (int i = n - 1; i; --i)
            data[i] = merge(data[i << 1], data[i << 1 | 1]);
    }
    T query(int l, int r) {
        T li = unit, ri = unit;
        for (l += n, r += n; l < r; r >>= 1, l >>= 1) {
            if (l & 1) li = merge(li, data[l++]);
            if (r & 1) ri = merge(data[--r], ri);
        }
        return merge(li, ri);
    }
    void update(int i, int d) {
        for (data[i += n] = getSingle(d); i > 1; i >>= 1)
            data[i >> 1] = merge(data[i & ~1], data[i | 1]);
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    F0R(n, 100) {
        mod cnt = 0;
        F0R(i, min(10, n + 1))
            cnt += n - i < 10;
        dp[n] = cnt;
    }

    int n, m;
    string s;
    cin >> n >> m >> s;

    ST st(n);
    F0R(i, n) st.data[n + i] = getSingle(s[i] - '0');
    st.build();

    while(m--) {
        int x, d;
        cin >> x >> d;

        st.update(x - 1, d);
        cout << st.query(0, n).withLR << endl;
    }

}


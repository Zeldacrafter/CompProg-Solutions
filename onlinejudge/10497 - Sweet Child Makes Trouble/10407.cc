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
#define bk back()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define SET(a, b) memset((a), (b), sizeof(a))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
  if (DEBUG) std::cerr
#define dvar(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
template <class a, class b>
ostream& operator<<(ostream& o, const pair<a, b>& p);
template <class T> struct IsC {
  template <class C> static char test(typename C::const_iterator*);
  template <class C> static int test(...);
  static const bool value = sizeof(test<T>(0)) == sizeof(char);
};
template <> struct IsC<string> { static const bool value = false; };
template <class C> typename enable_if<IsC<C>::value, ostream&>::type operator<<( ostream& o, const C& c) {
  o << '{';
  for (auto it = c.begin(); it != c.end();)
    o << *it << (++it != c.end() ? ", " : "}");
  return o;
}
template <class a, class b> ostream& operator<<(ostream& o, const pair<a, b>& p) {
  return o << '(' << p.fi << ", " << p.se << ')';
}

template <class T>
int sign(T a) {
  return (a > 0) - (0 > a);
}
using vll = vector<ll>;
using vit = vll::iterator;
struct bigint {
  static const ll base = 1e9;
  int signum;
  vll mag;
  bigint() : signum(0), mag() {}
  bigint(ll val) : signum(sign(val)), mag() {
    val = abs(val);
    while (val) mag.pb(val % base), val /= base;
  }
  bigint(int sig, vll&& mag) : signum(sig), mag(mag) {
    if (!sig) mag.clear();
    trim();
  }
  bigint(string s) {
    if (s.empty() || s == "0")
      signum = 0;
    else {
      signum = s[0] == '-' ? -1 : 1;
      for (int i = SZ(s) - 1, j = 0, b = 1; ~i && isdigit(s[i]);
           --i, ++j, b *= 10) {
        if (b == base) j = 0, b = 1;
        if (!j) mag.pb(0);
        mag.bk += (s[i] - '0') * b;
      }
    }
  }
  size_t size() { return mag.size(); }
  static void trim(vll& v) {
    while (SZ(v) && !v.bk) v.pop_back();
  }
  void trim() {
    trim(mag);
    if (mag.empty()) signum = 0;
  }
  ll val(int index) { return index < SZ(mag) ? mag[index] : 0; }
  friend bigint operator-(bigint a) {
    a.signum *= -1;
    return a;
  }
  bigint& operator+=(ll val) {
    bigint t{val};
    return (*this) += t;
  }
  bigint& operator+=(bigint& other) {
    if (!other.signum) return *this;
    if (!signum) return *this = other;
    if (signum == other.signum)
      add_to(mag, ALL(other.mag));
    else if (less(ALL(mag), ALL(other.mag)))
      signum *= -1, mag = sub(ALL(other.mag), ALL(mag));
    else
      sub_from(mag, ALL(other.mag));
    trim();
    return *this;
  }
  friend bigint operator+(bigint a, bigint& b) { return a += b; }
  friend bigint operator+(bigint a, ll val) { return a += val; }
  friend bigint operator+(ll val, bigint a) { return a += val; }
  static vll add(vit ab, vit ae, vit bb, vit be) {
    vll out(ab, ae);
    add_to(out, bb, be);
    return out;
  }
  static void add_to(vll& v, vit ob, vit oe) {
    v.resize(max(SZ(v), (int)distance(ob, oe)) + 1);
    for (int i = 0, c = 0; ob != oe || c; ++i) {
      v[i] += (ob != oe ? *ob : 0) + c;
      c = v[i] >= base;
      v[i] %= base;
      if (ob != oe) ++ob;
    }
    trim(v);
  }
  bigint& operator-=(ll val) {
    bigint t{val};
    return (*this) -= t;
  }
  bigint& operator-=(bigint& other) {
    if (!other.signum) return *this;
    if (!signum) {
      mag = other.mag;
      signum = -1 * other.signum;
      return *this;
    }
    if (signum != other.signum)
      add_to(mag, ALL(other.mag));
    else if (less(ALL(mag), ALL(other.mag)))
      signum *= -1, mag = sub(ALL(other.mag), ALL(mag));
    else
      sub_from(mag, ALL(other.mag));
    trim();
    return *this;
  }
  friend bigint operator-(bigint a, bigint& b) { return a -= b; }
  friend bigint operator-(bigint a, ll val) { return a -= val; }
  friend bigint operator-(ll val, bigint a) { return a -= val; }
  static vll sub(vit ab, vit ae, vit bb, vit be) {
    // assert(!less(ab, ae, bb, be));
    vll out(ab, ae);
    sub_from(out, bb, be);
    return out;
  }
  static void sub_from(vll& v, vit ob, vit oe) {
    // assert(!less(ALL(v), ob, oe));
    if (ob == oe) return;
    for (int i = 0, c = 0; ob != oe || c; ++i) {
      ll sub = (ob != oe ? *ob : 0) + c;
      c = 0;
      if (v[i] < sub) c = 1, v[i] += base;
      v[i] -= sub;
      if (ob != oe) ++ob;
    }
    trim(v);
  }
  bigint& operator*=(ll val) {
    if (!signum || !val) {
      signum = 0, mag.clear();
      return *this;
    }
    mag = small_mult(ALL(mag), val);
    signum *= sign(val);
    return *this;
  }
  bigint& operator*=(bigint& other) {
    if (!signum || !other.signum) {
      signum = 0, mag.clear();
      return *this;
    }
    mag = karat_mult(ALL(mag), ALL(other.mag));
    signum *= other.signum;
    return *this;
  }
  friend bigint operator*(bigint a, bigint& b) { return a *= b; }
  friend bigint operator*(bigint a, ll val) { return a *= val; }
  friend bigint operator*(ll val, bigint a) { return a *= val; }
  static vll karat_mult(vit ab, vit ae, vit bb, vit be) {
    if (ab == ae || bb == be) return vll();
    if (distance(ab, ae) < distance(bb, be))
      swap(ab, bb), swap(ae, be);
    if (distance(bb, be) == 1) return small_mult(ab, ae, *bb);
    int split = distance(ab, ae) / 2;
    vit amid = ab + split,
        bmid = bb + min(split, (int)distance(bb, be));
    vll z0 = karat_mult(ab, amid, bb, bmid);
    vll z2 = karat_mult(amid, ae, bmid, be);
    vll x1x0 = add(ab, amid, amid, ae);
    vll y1y0 = add(bb, bmid, bmid, be);
    vll z1 = karat_mult(ALL(x1x0), ALL(y1y0));
    sub_from(z1, ALL(z2));
    sub_from(z1, ALL(z0));
    vll out(max({SZ(z0), split + SZ(z1), split * 2 + SZ(z2)}) + 1);
    auto add = [&](vll& v, int offset) {
      for (int i = 0, c = 0; i < SZ(v) || c; ++i) {
        out[i + offset] += (i < SZ(v) ? v[i] : 0) + c;
        c = out[i + offset] >= base;
        out[i + offset] %= base;
      }
    };
    add(z0, 0);
    add(z1, split);
    add(z2, split * 2);
    trim(out);
    return out;
  }
  static vll small_mult(vit ab, vit ae, ll fac) {
    if (ab == ae || fac == 0) return vll();
    vll out(ab, ae);
    ll c = 0;
    for (int i = 0; i < SZ(out) || c; ++i) {
      if (i == SZ(out)) out.pb(0);
      out[i] = out[i] * fac + c;
      c = out[i] / base;
      out[i] %= base;
    }
    trim(out);
    return out;
  }
  friend bool operator<(bigint& a, bigint& b) {
    if (a.signum != b.signum) return a.signum < b.signum;
    if (!a.signum) return false;
    int c = cmp(ALL(a.mag), ALL(b.mag));
    return a.signum > 0 ? c < 0 : c > 0;
  }
  static int less(vit ab, vit ae, vit bb, vit be) {
    return cmp(ab, ae, bb, be) < 0;
  }
  static int cmp(vit ab, vit ae, vit bb, vit be) {
    if (ab == ae && bb == be) return 0;
    auto cmp = sign(distance(ab, ae) - distance(bb, be));
    if (cmp) return cmp;
    do {
      ae = prev(ae), be = prev(be);
      cmp = sign(*ae - *be);
    } while (!cmp && ae != ab);
    return cmp;
  }
  friend string to_string(bigint& bi) {
    if (!bi.signum) return "0";
    stringstream ss;
    ss << bi.signum * bi.mag.bk;
    R0F (i, SZ(bi) - 2)
      ss << setfill('0') << setw(9) << bi.mag[i];
    return ss.str();
  }
  friend ostream& operator<<(ostream& o, bigint& bi) {
    return o << to_string(bi);
  }
};



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<bigint> der(801);
    der[0] = 1;
    der[1] = 0;
    FOR(i, 2, 801) {
        der[i] = der[i - 1] + der[i - 2];
        der[i] *= (i - 1);
    }

    while(1) {
        int k;
        cin >> k;
        if(k == -1)
            break;
        cout << der[k] << endl;
    }
}

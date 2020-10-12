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
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (int)(x).size()
#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR (a, 0, (b))
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
#define dout if (DEBUG) cerr
#define dvar(...) " \x1b[35m[" << #__VA_ARGS__ ": " << mt(__VA_ARGS__) << "]\x1b[0m "
template <typename T>
true_type const_iterator_check(typename T::const_iterator*);
template <typename T>
false_type const_iterator_check(...);
template <typename T>
struct IsC : decltype(const_iterator_check<T>(nullptr)) {};
template <>
struct IsC<string> : false_type {};
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
  for (const auto& vv : v) {
    for (const auto& i : vv) o << setw(width) << i;
    o << endl;
  }
}

void solve() {
    int n;
    cin >> n;
    
    multiset<int, greater<int>> odd, even;
    FOR(i, 1, n + 1) {
        if(i & 1) odd.insert(i);
        else even.insert(i);
    }

    vii res;
    int lastNum = -1;
    while(SZ(odd) > 1 || SZ(even) > 1) {
        int aOdd = -1, bOdd = -1;
        if(SZ(odd) > 1) {
            aOdd = *odd.begin();
            odd.erase(odd.begin());
            bOdd = *odd.begin();
            odd.erase(odd.begin());
        }
        int aEven = -1, bEven = -1;
        if(SZ(even) > 1) {
            aEven = *even.begin();
            even.erase(even.begin());
            bEven = *even.begin();
            even.erase(even.begin());
        }

        int sOdd = (aOdd + bOdd + 1)/2;
        int sEven = (aEven + bEven + 1)/2;
        if(sOdd > sEven) {
            res.eb(aOdd, bOdd);
            if(aEven != -1)
                even.insert(aEven);
            if(bEven != -1)
                even.insert(bEven);
        } else {
            res.eb(aEven, bEven);
            if(aOdd != -1)
                odd.insert(aOdd);
            if(bOdd != -1)
                odd.insert(bOdd);
        }
        
        lastNum = max(sOdd, sEven);
        if(lastNum & 1)
            odd.insert(lastNum);
        else
            even.insert(lastNum);
    }

    if(SZ(odd) == 1 && SZ(even) == 1) {
        int a = *odd.begin();
        int b = *even.begin();
        res.eb(a, b);
        lastNum = (a + b + 1)/2;
    }

    cout << lastNum << endl;
    for(auto [a, b] : res)
        cout << a << ' ' << b << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc = 1;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}


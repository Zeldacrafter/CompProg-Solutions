#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
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
  for (const auto& vv : v) {
    for (const auto& i : vv) o << setw(width) << i;
    o << endl;
  }
}


vector<vector<bool>> seen;
vvvii adj;

int solveIt(ii p1, ii p2, bool turn1, bool done1, bool done2, int score) {
    if(done1 && done2) return score;

    if(turn1) {
        int res = -1e9;

        bool doneSth = false;
        for(ii& x : adj[p1.fi][p1.se]) {
            if(!seen[x.fi][x.se]) {
                doneSth = true;
                
                seen[x.fi][x.se] = true;
                ckmax(res, solveIt(x, p2, !turn1, done1, done2, score + 1));
                seen[x.fi][x.se] = false;
            }
        }

        // cannot move
        if(!doneSth)
            ckmax(res, solveIt(p1, p2, !turn1, true, done2, score));

        return res;
    } else {
        int res = 1e9;

        bool doneSth = false;

        for(ii& x : adj[p2.fi][p2.se]) {
            if(!seen[x.fi][x.se]) {
                doneSth = true;
                
                seen[x.fi][x.se] = true;
                ckmin(res, solveIt(p1, x, !turn1, done1, done2, score - 1));
                seen[x.fi][x.se] = false;
            }
        }

        // cannot move
        if(!doneSth)
            ckmin(res, solveIt(p1, p2, !turn1, done1, true, score));

        return res;
    }
}

void solve() {
    int s, c;
    ii p1, p2;
    cin >> s >> p1.fi >> p1.se >> p2.fi >> p2.se >> c;
    p1.fi--; p1.se--; p2.fi--; p2.se--;

    adj = vvvii(s);
    F0R(r, s) {
        adj[r] = vvii(1 + 2*r);
        F0R(c, 1 + 2*r) {
            if(r && c % 2 == 1 && r) {
                adj[r][c].eb(r - 1, c - 1);
                adj[r - 1][c - 1].eb(r, c);
            }
            if(c) {
                adj[r][c].eb(r, c - 1);
                adj[r][c - 1].eb(r, c);
            }
        }
    }

    seen = vector<vector<bool>>(s);
    F0R(i, s) seen[i] = vector<bool>(1 + 2*i, false);

    F0R(i, c) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        seen[a][b] = true;
    }

    seen[p1.fi][p1.se] = seen[p2.fi][p2.se] = true;
    int res = solveIt(p1, p2, true, false, false, 0);
    cout << res << endl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int tc = 1;
  cin >> tc;
  FOR(i, 1, tc + 1) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

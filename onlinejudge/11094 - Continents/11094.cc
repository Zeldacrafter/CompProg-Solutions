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

vector<string> inp;
vector<vector<bool>> seen;
int cols, rows;
char land;

const int dr[4] = {0, 0, -1, 1}, dc[4] = {1, -1, 0, 0};

int dfs(int r, int c) {
    seen[r][c] = true;

    int res = 1;
    F0R(i, 4) {
        int rr = r + dr[i], cc = (c + dc[i] + cols) % cols;
        if(rr < 0 || rr >= rows || inp[rr][cc] != land || seen[rr][cc])
            continue;

        res += dfs(rr, cc);
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin >> rows >> cols) {
        seen = vector<vector<bool>>(rows, vector<bool>(cols));

        inp.resize(rows);
        F0R(r, rows)
            cin >> inp[r];

        int sR, sC;
        cin >> sR >> sC;
        land = inp[sR][sC];

        dfs(sR, sC);

        int best = 0;
        F0R(r, rows)
            F0R(c, cols)
                if(inp[r][c] == land && !seen[r][c])
                    ckmax(best, dfs(r, c));
        cout << best << endl;

    }
}

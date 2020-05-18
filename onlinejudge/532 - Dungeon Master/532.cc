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

const int dx[6] = {1, -1, 0, 0, 0, 0}, dy[6] = {0, 0, 1, -1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};

int L, R, C;
vector<vector<string>> inp;
vector<vector<vector<bool>>> seen;

bool ok(int x, int y, int z) {
    return x >= 0 && y >= 0 && z >= 0 && x < L && y < R && z < C && inp[x][y][z] != '#';
}
void solve() {
    inp = vector<vector<string>>(L, vector<string>(R));
    seen = vector<vector<vector<bool>>>(L, vector<vector<bool>>(R, vector<bool>(C)));
    int sX, sY, sZ;
    F0R(i, L)
        F0R(j, R) {
            cin >> inp[i][j];
            F0R(k, C)
                if(inp[i][j][k] == 'S')
                    sX = i, sY = j, sZ = k;
        }

    queue<array<int, 4>> q;
    q.push({sX, sY, sZ, 0});
    while(!q.empty()) {
        array<int, 4> curr = q.front();
        q.pop();
        if(inp[curr[0]][curr[1]][curr[2]] == 'E') {
            cout << "Escaped in " << curr[3] << " minute(s).\n";
            return;
        }

        F0R(i, 6) {
            int x = curr[0] + dx[i], y = curr[1] + dy[i], z = curr[2] + dz[i];
            if(!ok(x, y, z) || seen[x][y][z])
                continue;
            seen[x][y][z] = true;
            q.push({x, y, z, curr[3] + 1});
        }
    }
    cout << "Trapped!\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(1) {
        cin >> L >> R >> C;
        if(!L && !R && !C)
            break;
        solve();
    }

}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pf push_front
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ge(a, b) get<(b)>((a))
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmin(t& a, const t& b) {return a > b ? a = b, true : false;}
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}
#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
if (DEBUG) std::cerr

class unionFind {
 public:
  unionFind(int size)
      : _size(size), data(size, -1) {}
  int find(int toFind) {
    int root = toFind;
    while (data[root] >= 0)
      root = data[root];
    while (toFind != root) {
      int tmp = data[toFind];
      data[toFind] = root;
      toFind = tmp;
    }
    return root;
  }
  void join(int a, int b) {
    if (data[a] < data[b]) {
      data[a] += data[b];
      data[b] = a;
    } else {
      data[b] += data[a];
      data[a] = b;
    }
    _size--;
  }
  int size() { return _size; }
  int size(int a) { return -data[a]; }

 private:
  vi data;
  int _size;
}; 

void solve() {
    int F, cnt = 0;
    cin >> F;

    unionFind uf(2*F);

    map<string, int> ind;
    F0R(i, F) {
        string a, b;
        cin >> a >> b;

        if(!ind.count(a))
            ind[a] = cnt++;
        if(!ind.count(b))
            ind[b] = cnt++;

        if(uf.find(ind[a]) != uf.find(ind[b]))
            uf.join(uf.find(ind[a]), uf.find(ind[b]));

        cout << uf.size(uf.find(ind[a])) << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


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
template<typename T> struct range : public pair<T, T> {
  template<typename U> struct it : iterator<forward_iterator_tag, U> {
    U v;
    it(U vv) : v(vv) {}
    operator U&() { return v; }
    U operator*() { return v; }
  };
  range(T b, T e) : pair<T, T>(b, e) {}
  range(T e) : pair<T, T>(static_cast<T>(0), e) {}
  it<T> begin() { return this->fi; }
  it<T> end() { return this->se; }
  bool in(T v) { return this->fi <= v && v < this->se; }
};

const int MAXN = 2001;

int n, p;
vi a;

bool f(int x) {
    for(int i : range(n))
        if((i - max(a[i] - x, 0) + 1) % p == 0)
            return false;
    return true;
}

void solve() {
    cin >> n >> p;

    a = vi(n);
    for(int i : range(n)) cin >> a[i];
    sort(ALL(a));

    int minVal = 0;
    for(int i : range(n))
        ckmax(minVal, a[i] - i);

    vi res; 
    for(int x : range(minVal, MAXN))
        if(f(x))
            res.pb(x);

    cout << SZ(res) << endl;
    for(int x : res) cout << x << ' ';
    cout << endl;
    
}

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);

  int tt = 1;
  FOR (t, 1, tt + 1)
    solve();
  
  return 0;
}


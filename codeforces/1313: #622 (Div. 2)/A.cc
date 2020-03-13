
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define ROF(a, b, c) for(auto (a) = (b); (a) >= (c); --(a))
#define R0F(a, b) ROF(a, b, 0)
#define pb push_back
#define eb emplace_back
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define fst first
#define snd second
template <typename T>
void ckMin(T& a, T b) { a = min(a, b); }
template <typename T>
void ckMax(T& a, T b) { a = max(a, b); }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
      int ar[3];
      cin >> ar[0] >> ar[1] >> ar[2];

      sort(ar, ar + 3, std::greater<int>());

      int res = 0;
      for(int i = 1; i < (1 << 3); ++i) {
          bool ok = true;
          for(int j = 0; j < 3; ++j) {
              if(!(i & (1 << j))) {
                continue;
              }
              if(!ar[j]) {
                  ok = false;
                  break;
              }
          }
          if(!ok) continue;

        
          res++;
          for(int j = 0; j < 3; ++j)
              if(i & (1 << j))
                  ar[j]--;
      }
      cout << res << endl;
    }
}

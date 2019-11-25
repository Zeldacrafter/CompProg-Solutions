#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))

int main() {
  int tc;
  scanf("%d", &tc);

  FOR(testCase, 1, tc + 1) {
    int n;
    scanf("%d", &n);

    int mile = 0;
    int juice = 0;
    FOR(i, 0, n) {
      int minutes;
      scanf("%d", &minutes);

      mile += (minutes / 30 + 1) * 10;
      juice += (minutes / 60 + 1) * 15;
    }

    if (mile < juice)
      printf("Case %d: Mile %d\n", testCase, mile);
    else if (juice < mile)
      printf("Case %d: Juice %d\n", testCase, juice);
    else
      printf("Case %d: Mile Juice %d\n", testCase, mile);
  }
}

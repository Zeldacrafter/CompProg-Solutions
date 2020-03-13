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

  FOR(i, 1, tc + 1) {
    int jumps;
    scanf("%d", &jumps);

    int lowCount = 0;
    int highCount = 0;

    int currVal;
    scanf("%d", &currVal);
    jumps--;

    while (jumps--) {
      int nextVal;
      scanf("%d", &nextVal);

      if (nextVal > currVal)
        highCount++;
      else if (nextVal < currVal)
        lowCount++;

      currVal = nextVal;
    }

    printf("Case %d: %d %d\n", i, highCount, lowCount);
  }

  return 0;
}

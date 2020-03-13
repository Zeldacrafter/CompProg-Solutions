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

bitset<3010> bits;

int main() {

    int elems;
    while (scanf("%d", &elems) != EOF) {
        bits.reset();

        int last, curr;
        scanf("%d", &curr);

        bool jolly = true;
        FOR(i, 1, elems) {
            last = curr;
            scanf("%d", &curr);
            int dist = abs(last - curr);
            if(bits[dist] || !dist || dist >= elems) jolly = false;
            bits[dist] = true;
        }

        if (jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

  return 0;
}

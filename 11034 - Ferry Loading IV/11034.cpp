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

    queue<int> left;
    queue<int> right;

    while(tc--) {
        int length;
        int carC;
        scanf("%d %d", &length, &carC);

        length = length * 100; //m to cm

        FOR(i, 0, carC) {
            int carLen;
            char buffer[10] = {};
            scanf("%d %10s", &carLen, buffer);

            switch(buffer[0]) {
                case 'l':
                    left.push(carLen);
                    break;
                case 'r':
                    right.push(carLen);
                    break;
                default:
                    assert(false);
                    break;
            }
        }

        bool ferryOnLeft = true;
        int crossCount = 0;
        while(left.size() > 0 || right.size() > 0) {
            int lengthLeft = length;
            
            if(ferryOnLeft) {
                while(left.size() > 0 && left.front() <= lengthLeft) {
                    lengthLeft -= left.front();
                    left.pop();
                }
            } else {
                while(right.size() > 0 && right.front() <= lengthLeft) {
                    lengthLeft -= right.front();
                    right.pop();
                }
            }

            crossCount++;
            ferryOnLeft = !ferryOnLeft;
        }

        printf("%d\n", crossCount);
    }

    return 0;
}

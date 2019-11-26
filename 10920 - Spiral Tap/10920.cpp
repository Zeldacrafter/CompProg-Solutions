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

    int size;
    int point;

    while(true) {
        scanf("%d %d", &size, &point);
        if(!size && !point) break;

        int ring = 1;
        while( ((ring-1)*2 + 1) * ((ring-1)*2 + 1) < point) ring++;

        point -= ((ring - 2)*2 + 1)*((ring - 2)*2 + 1);

        int outsideRings = (size - (2*ring - 1))/2;
        int insideDiam = (ring - 1)*2 + 1;
        int tillTurn = (ring - 1)*2;
        int ringBorderLength = (ring - 1)*2;

        int line;
        int column;
        if(point - ringBorderLength <= 0) {
            line = outsideRings + insideDiam;
            column = outsideRings + tillTurn - point + 1;
        }else if(point - 2*ringBorderLength <= 0) {
            point -= ringBorderLength;
            line = outsideRings + tillTurn - point + 1;
            column = outsideRings + 1;
        }else if(point - 3*ringBorderLength <= 0) {
            point -= 2*ringBorderLength;
            line = outsideRings + 1;
            column = outsideRings + 1 + point;
        }else {
            point -= 3*ringBorderLength;
            line = outsideRings + 1 + point;
            column = outsideRings + insideDiam;
        }
        printf("Line = %d, column = %d.\n", line, column);
    }

    return 0;
}

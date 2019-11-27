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

#define SIZE 500
char bigSq[SIZE][SIZE];  //Used for 0° and 180° rotation.
char bigSq2[SIZE][SIZE]; //Used for 90° and 270° rotation.
char smallSq[SIZE][SIZE];
int bigSize;
int smallSize;

int searchIn(char big[500][500]) {
    int count = 0;
    FOR(xBig, 0, bigSize - smallSize + 1) {
        FOR(yBig, 0, bigSize - smallSize + 1) {

            bool found = true;
            for(int xSmall = 0; found && xSmall < smallSize; xSmall++) {
                for(int ySmall = 0; found && ySmall < smallSize; ySmall++) {
                    if(big[xBig + xSmall][yBig + ySmall] != smallSq[xSmall][ySmall]) 
                        found = false;
                }
            }

            if(found == true) count++;
        }
    }
    return count;
}

void rotate90Deg(char from[SIZE][SIZE], char to[SIZE][SIZE]) {
    FOR(x, 0, bigSize) {
        FOR(y, 0, bigSize) {
            to[bigSize - 1 - y][x] = from[x][y];
        }
    }
}

int main() {

    while(true) {
        scanf("%d %d", &bigSize, &smallSize);
        if(!bigSize && !smallSize) break;

        // Input
        FOR(i, 0, bigSize) scanf(" %500[A-Z]", bigSq[i]);
        FOR(i, 0, smallSize) scanf(" %500[A-Z]", smallSq[i]);

        // Caluculation
        int rot0 = searchIn(bigSq);
        rotate90Deg(bigSq, bigSq2);
        int rot90 = searchIn(bigSq2);
        rotate90Deg(bigSq2, bigSq);
        int rot180 = searchIn(bigSq);
        rotate90Deg(bigSq, bigSq2);
        int rot270 = searchIn(bigSq2);


        printf("%d %d %d %d\n", rot0, rot90, rot180, rot270);
    }


    return 0;
}

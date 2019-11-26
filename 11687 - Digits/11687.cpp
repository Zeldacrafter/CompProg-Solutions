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

char buffer[1000100];

int main() {

    while(true) {
        scanf(" %1000100[0-9E]", buffer);
        if(buffer[0] == 'E') break;

        int count = 1;
        int newLen = strlen(buffer);
        int len;
        if(newLen > 10)
            len = -1;
        else
            sscanf(buffer, "%d", &len);

        if(len != newLen) {
            while(len != newLen) {
                len = newLen;
                newLen = log10(len) + 1;
                count++;
            }
        } else
            count = 1;

        printf("%d\n", count);
    }

    return 0;
}

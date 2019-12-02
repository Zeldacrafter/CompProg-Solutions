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

char line[100100];

int main() {

    while(scanf("%s", line) != EOF) {
        list<char> res;
        int length = strlen(line);
        list<char>::iterator it = res.begin();

        FOR(i, 0, length) {
            if(line[i] == '[') 
                it = res.begin();
            else if (line[i] == ']') 
                it = res.end();
            else 
                res.insert(it, line[i]);
        }

        FORI(iter, res) printf("%c", *iter);
        printf("\n");
    }

    return 0;
}

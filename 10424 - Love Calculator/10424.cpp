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

char name1[26] = {};
char name2[26] = {};

int digRoot(int n) {
    if(n < 10) return n;
    
    int res = 0;
    while(n) {
        res += n % 10;
        n /= 10;
    }
    return digRoot(res);
}

int getNr(char buffer[26]) {
    int res = 0;
    for(int i = 0; buffer[i] != 0 && buffer[i] != '\n'; ++i) {
        char c = buffer[i];
        if(c >= 'A' && c <= 'Z') {
            res += c - 'A' + 1;
        } else if (c >= 'a' && c <= 'z') {
            res += c - 'a' + 1;
        }
    }
    return digRoot(res);
}

int main() { 

    while(true) {

        if(!fgets(name1, 26, stdin)) break;
        if(!fgets(name2, 26, stdin)) break;        
        
        int nr1 = getNr(name1);
        int nr2 = getNr(name2);

        printf("%.2f %%\n", 100 * min(nr1, nr2) / (float)max(nr1, nr2));

        memset(name1, 0, sizeof(name1));
        memset(name2, 0, sizeof(name2));
    }

    return 0;
}

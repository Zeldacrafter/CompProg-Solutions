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
    getchar();
    
    while(tc--) {

        string s;
        getline(cin, s);

        int m = 0;
        int f = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                if (s[i] == 'M') m++;
                else if (s[i] == 'F') f++;
            }

        }

        if( (m == f) && s.size() > 2)
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }

    return 0;
}

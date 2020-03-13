#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define fst first
#define snd second

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        string path;
        cin >> n >> path; 

        ii curr(0, 0);
        map<ii, int> lastSeen;
        lastSeen[curr] = 0; 

        int len = n + 2;
        int l = 0;
        F0R(i, n) {
            if(path[i] == 'L')
                curr.fst--;
            else if(path[i] == 'R')
                curr.fst++;
            else if(path[i] == 'U')
                curr.snd++;
            else if(path[i] == 'D')
                curr.snd--;

            if(lastSeen.find(curr) != lastSeen.end() && len > i - lastSeen[curr] + 1) {
                len = i - lastSeen[curr] + 1;
                l = lastSeen[curr];
            }
            lastSeen[curr] = i + 1;
        }
   
        if(len > n)
            cout << -1 << endl;
        else
            cout << 1 + l << ' ' << l + len << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        string s;
        cin >> n >> s;

        int skipCnt = 0;
        int c = n;
        int curr = n;
        F0R(i, n) {
            if(s[i] == '<') {
                skipCnt++;
            } else {
                F0R(i, skipCnt + 1)
                    cout << curr - skipCnt + i << (--c ? '\n' : ' ');
                curr -= skipCnt + 1;
                skipCnt = 0;
            }
        }
        F0R(i, skipCnt)
            cout << curr - skipCnt + i << (--c ? '\n' : ' ');

        
        int currDec = 0;
        F0R(i, n)
            if(s[i] == '>')
                off++;

        int currInc = currDec + 1;

        cout << currInc++ << ' ';
        F0R(i, n - 1) {
            if(s[i] == '<')
                cout << currInc++ << (i != n - 2 ? ' ' : endl);
            else
                cout << currDec-- << (i != n - 2 ? ' ' : endl);
        }

    }
}

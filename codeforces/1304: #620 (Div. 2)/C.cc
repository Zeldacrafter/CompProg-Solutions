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
        int n, temp;
        cin >> n >> temp;
        
        int lastL = temp;
        int lastH = temp;
        int lastT = 0;

        bool failed = false;
        F0R(i, n) {
            int t, l, h;
            cin >> t >> l >> h;

            if(failed)
                continue;

            int dt = t - lastT;
            lastL -= dt;
            lastH += dt;
            lastT = t;

            if(lastH < l || lastL > h)
                failed = true;
            else {
                lastL = max(lastL, l);
                lastH = min(lastH, h); 
            } 
        }

        if(failed)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

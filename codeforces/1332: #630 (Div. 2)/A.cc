#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool ok(int a, int b, int x, int x1, int x2) {
    if(a > 0 && b > 0) {
        int dxRight = x2 - x;
        int dxLeft = x - x1;
        if(!dxLeft && !dxRight)
            return false;
        if(dxRight + a < b || dxLeft + b < a)
            return false;
    } else if(a > 0) {
        if(x - a < x1)
            return false;
    } else if(b > 0) {
        if(x + b > x2) 
            return false;
    }
    return true;
}

void solve() {
    int a, b, c, d, x, x1, x2, y, y1, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;

    if(ok(a, b, x, x1, x2) && ok(c, d, y, y1, y2))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


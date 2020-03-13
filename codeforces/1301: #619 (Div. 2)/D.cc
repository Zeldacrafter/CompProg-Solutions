#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define endl '\n'
 
ll k;
void move(ll c, char dir) {
    static string s = "";
    static int cnt = 0;
    if(!c) return;

    s += to_string(min(k, c)) + ' ' + dir + '\n';
    k -= min(k, c);
    cnt++;
    if(!k) {
        cout << cnt << endl << s;
        exit(0);
    }
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    ll rows, cols;
    cin >> rows >> cols >> k;
 
    if(4*rows*cols - 2*rows - 2*cols < k) {
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";

    FOR(i, 0, rows - 1) {
        move(cols - 1, 'R');
        move(cols - 1, 'L');
        move(1, 'D');
    }
    move(cols - 1, 'R');
    F0R(i, cols - 1) {
        move(rows - 1, 'U');
        move(rows - 1, 'D');
        move(1, 'L');
    }
    move(rows - 1, 'U');
 
    assert(!k);
    return 0;
}



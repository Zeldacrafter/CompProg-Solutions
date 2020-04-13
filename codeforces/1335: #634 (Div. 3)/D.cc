#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define eb emplace_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

const int MAXN = 9;
char s[MAXN][MAXN];

void solve() {
    F0R(r, MAXN)
        F0R(c, MAXN)
            cin >> s[r][c];

    vii todo;
    F0R(r, MAXN)
        F0R(c, MAXN)
            if(s[r][c] == '1')
                todo.eb(r, c/3*3 + (c + 1) % 3);

    for(auto [r, c] : todo)
        s[r][c] = '1';

    F0R(r, MAXN) {
        F0R(c, MAXN)
            cout << s[r][c];
        cout << endl;
    }

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    
    vi first(n), last(n);
    int cnt = 0;
    F0R(i, n) {
        if(s[i] == 'x') continue;

        first[i] = ++cnt;
        if(cnt == k) break;
        i += c;
    }
    R0F(i, n - 1) {
        if(s[i] == 'x') continue;

        last[i] = cnt--;
        if(!cnt) break;
        i -= c;
    }
    F0R(i, n)
        if(first[i] && first[i] == last[i])
            cout << i + 1 << endl;
}



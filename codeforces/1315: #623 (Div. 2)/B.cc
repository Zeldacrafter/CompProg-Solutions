#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define endl '\n'

void solve() {

    int a, b, p;
    string s;
    cin >> a >> b >> p >> s;

    int currC = 0;
    char lastC = 'C';
    for(int i = SZ(s) - 2; i >= 0; --i) {
        if(lastC != s[i]) {
            if(s[i] == 'A') {
                if(currC + a > p) {
                    cout << i + 2 << endl;
                    return;
                }
                currC += a;
            } else if (s[i] == 'B') {
                if(currC + b > p) {
                    cout << i + 2 << endl;
                    return;
                }
                currC += b;
            }
            lastC = s[i];
        }
    }
    cout << 1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

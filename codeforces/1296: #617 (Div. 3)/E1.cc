#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define CLR(a, b) memset((a), (b), sizeof((a)))

int color[210];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    CLR(color, -1);

    int n;
    string s;
    cin >> n >> s;

    F0R(i, n) {
        F0R(j, i) {
            if(s[i] < s[j]) {
                if(color[i] == -1 && color[j] == -1) {
                    color[i] = 1;
                    color[j] = 0;
                } else if(color[i] == -1)
                    color[i] = !color[j];
                else if(color[j] == -1)
                    color[j] = !color[i];
                else if(color[i] == color[j]) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    F0R(i, n)
        cout << (color[i] == -1 ? 0 : color[i]);
    cout << endl;
}


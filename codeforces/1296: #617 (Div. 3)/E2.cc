#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define SZ(x) (x).size()

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    vi res(n);
    vi colors;
    F0R(j, n) {
        int bestC = -1;
        F0R(i, SZ(colors))
            if(colors[i] <= s[j] && (bestC == -1 || colors[i] > colors[bestC]))
                bestC = i;

        if(bestC == -1) {
            colors.pb(s[j]);
            res[j] = SZ(colors) - 1;
        } else {
            colors[bestC] = s[j];
            res[j] = bestC;
        }
    }

    cout << SZ(colors) << endl;
    F0R(i, n)
        cout << res[i] + 1 << " \n"[i == n - 1];
    
}


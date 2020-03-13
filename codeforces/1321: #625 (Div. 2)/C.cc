#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto (a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto (a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))

bitset<110> rem;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    ROF(c, 'z', 'a' - 1) {
        F0R(i, n) {
            if(s[i] != c - 1) continue;

            for(int j = i + 1; j < n && (rem[j] || s[j] == c); j++)
                rem[j] = true;
            for(int j = i - 1; j >= 0 && (rem[j] || s[j] == c); --j)
                rem[j] = true;
        }
    }
    cout << rem.count() << endl;
}

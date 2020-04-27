#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    unordered_set<string> s;
    string str;
    F0R(i, n) {
        cin >> str;
        s.insert(str);
    }
    cout << SZ(s) << endl;
}



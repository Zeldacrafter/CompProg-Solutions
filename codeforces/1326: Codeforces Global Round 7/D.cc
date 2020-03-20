#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define CEIL(a, b) ((a) + (b)-1) / (b)

vi manacher(string s) {
    string T = "#";
    for (char c : s) T += c, T += '#';

    vi P(SZ(T));

    int c = 0, R = 0;
    FOR (i, 1, SZ(T) - 1) {
        if(R > i)
            P[i] = min(R - i, P[2 * c - i]);
        for(int r = i + 1 + P[i], 
                l = i - 1 - P[i];
             r < SZ(T) && l >= 0 && T[l] == T[r];
             l--, r++)
            P[i]++;
        if(i + P[i] > R) 
            c = i, R = i + P[i];
    }

    return P;
}

void solve() {
    string s;
    cin >> s;

    int l = 0;
    int r = SZ(s) - 1;
    while(r - 1 > l + 1 && s[r] == s[l]) {
        r--;
        l++;
    }
    string resOuter(s, 0, l);

    string midS(s, l, r - l + 1);
    vi P = manacher(midS);

    int maxLenL = 0;
    FOR(i, 1, SZ(P) - 1)
        if(P[i] == i)
            maxLenL = i;

    int maxLenR = 0;
    ROF(i, SZ(P) - 2, 1)
        if(P[i] == SZ(P) - i - 1)
            maxLenR = SZ(P) - i - 1;

    cout << resOuter
         << (maxLenL > maxLenR ? string(midS, 0, maxLenL)
                               : string(midS, SZ(midS) - maxLenR))
         << string(RALL(resOuter))
         << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


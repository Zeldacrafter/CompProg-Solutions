#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (x).size()

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    cout << (s[SZ(s) - 1] - '0') % 2;
}


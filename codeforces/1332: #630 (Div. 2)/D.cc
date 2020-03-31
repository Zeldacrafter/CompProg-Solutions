#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k;
    cin >> k;

    int higher = 1 << (32 - __builtin_clz(k));
    cout << 2 << ' ' << 3 << endl
         << (k | higher) << ' '  << k            << ' ' << 0 << endl
         << higher       << ' '  << (k | higher) << ' ' << k << endl;

}



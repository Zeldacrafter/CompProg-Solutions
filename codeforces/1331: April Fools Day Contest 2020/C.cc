#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int a;
    cin >> a;

    int res = 0;
    res |= ((a >> 0) & 1) << 4;
    res |= ((a >> 1) & 1) << 1;
    res |= ((a >> 2) & 1) << 3;
    res |= ((a >> 3) & 1) << 2;
    res |= ((a >> 4) & 1) << 0;
    res |= ((a >> 5) & 1) << 5;
    cout << res;
}


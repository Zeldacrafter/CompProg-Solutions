#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k, a, b;
    cin >> k >> a >> b;
    int lowest = a/k * k;
    if(lowest != a && lowest + k > b)
        cout << "NG";
    else
        cout << "OK";
}



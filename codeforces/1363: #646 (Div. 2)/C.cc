#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;

    int in = 0;
    for(int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        if(x == u || x == v)
            in++;
    }

    if(in <= 1)
        cout << "Ayush\n";
    else 
        cout << (n & 1 ? "Ashish" : "Ayush") << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
}


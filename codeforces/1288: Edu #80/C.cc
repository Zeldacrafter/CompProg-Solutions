#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int C[1100][1100];
ll binomKoeff(int n, int k){
    if(!k || n == k)
        return 1;

    if(C[n][k] == -1)
        C[n][k] = (binomKoeff(n - 1, k - 1) + binomKoeff(n - 1, k)) % MOD;

    return C[n][k];
}


int main() {
    ios_base::sync_with_stdio(0);

    memset(C, -1, sizeof(C));
    
    int n, m;
    cin >> n >> m;
    ll res = binomKoeff(n + 2*m - 1, 2*m);
    cout << res << '\n';
}

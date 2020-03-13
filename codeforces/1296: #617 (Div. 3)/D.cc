#include <bits/stdc++.h>
using namespace std;
 
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
 
int main() {
 
    int n, a, b, k;
    cin >> n >> a >> b >> k;
 
    map<int, int> skip;
    int m = 0;
    F0R(i, n) {
        int hp;
        cin >> hp;
 
        hp %= a + b;
        if(!hp)
            hp = a + b;
        
        int skips = (int)ceil(1.0*hp/a) - 1;
        m = max(m, skips);
        skip[skips]++;
    }
    
    int score = skip[0];
    for(int i = 1; i <= m && k >= i; ++i) {
        if(skip.find(i) == skip.end()) 
            continue;
 
        int take = min(skip[i], k/i);
        k -= take*i;
        score += take;
    }
 
    cout << score << endl;
    return 0;
}

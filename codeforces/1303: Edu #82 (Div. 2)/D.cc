#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(a, b, c) for (auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define endl '\n'

ll box[70];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;

        memset(box, 0, sizeof(box));
        F0R(i, m) {
            unsigned int k;
            cin >> k;
            ++box[31 - __builtin_clz(k)];
        }

        ll splitCnt = 0;
        F0R(bit, 65) {
            if(!n) break;

            if(n & (1LL << bit)) {
                if(!box[bit]) {
                    int splitBit = bit + 1;
                    while(!box[splitBit] && splitBit < 65)
                        splitBit++;
                    
                    if(splitBit == 65)
                        break;

                    FOR(i, bit + 1, splitBit)
                        box[i]++;

                    box[bit] += 2;
                    box[splitBit]--;
                    splitCnt += splitBit - bit;
                }
                box[bit]--;
                n ^= 1LL << bit;
            }

            box[bit+1] += box[bit]/2;
        }
        
        if(n)
            cout << -1 << endl;
        else
            cout << splitCnt << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define pb push_back


int getRes(vi &numsLeft, int currBit) {
    if(currBit < 0)
        return 0;
    
    vi hasSet;
    vi notSet;

    for(int a : numsLeft) {
        if(a & (1 << currBit))
            hasSet.pb(a);
        else
            notSet.pb(a);
    }

    if(hasSet.empty())
        return getRes(notSet, currBit - 1);
    if(notSet.empty())
        return getRes(hasSet, currBit - 1);
    return (1 << currBit) + 
            min(getRes(notSet, currBit - 1),
                getRes(hasSet, currBit - 1));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a;
    cin >> n;

    vi inp(n);
    F0R(j, n)
        cin >> inp[a];

    if(!n)
        cout << 0 << endl;
    else
        cout << getRes(inp, 30) << endl;

    return 0;
}

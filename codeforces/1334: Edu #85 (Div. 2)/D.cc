#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

void solve() {
    ll n, l ,r;
    cin >> n >> l >> r;

    ll forbidden = 1, currSteps = 0;
    for(; forbidden < n && currSteps + 2*(n - forbidden) < l; ++forbidden)
        currSteps += 2*(n - forbidden);
    ckmax(currSteps, 1ll);

    ll currNode = currSteps == 1 ? 1 : n;
    ll next = 2;
    for(; currSteps <= r; ++currSteps) {
        if(currSteps >= l)
            cout << currNode << " \n"[currSteps == r];

        if(currNode == n) {
            currNode = forbidden == n ? 1 : forbidden;
            next = forbidden + 1;
        } else {
            if(currNode == forbidden) {
                currNode = next++;
                if(next == n + 1)
                    forbidden++;
            } else
                currNode = forbidden;
        }
    }

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}


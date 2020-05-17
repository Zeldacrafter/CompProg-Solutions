#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pf push_front
#define pb push_back
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define SET(a, b) memset((a), (b), sizeof(a))

vi dep[26];
bitset<26> done;
vector<string> strs;

void solve() {
    done.reset();
    F0R(i, 26)
        dep[i].clear();

    int r, c;
    cin >> r >> c;

    strs = vector<string>(r);
    F0R(i, r)
        cin >> strs[i];

    F0R(i, r)
        F0R(j, c)
            FOR(k, i + 1, r)
                if(strs[k][j] != strs[i][j]) 
                    dep[strs[i][j] - 'A'].pb(strs[k][j] - 'A');

    string res;
    F0R(_, 26) {
        F0R(i, 26) {
            if(done[i]) continue;

            bool okThis = true;
            for(int k : dep[i])
                if(!done[k]) {
                    okThis = false;
                    break;
                }

            if(okThis) {
                done[i] = true;
                res.pb(i + 'A');
            }

        }
    }

    F0R(i, 26)
        if(!done[i]) {
            cout << -1 << endl;
            return;
        }

    cout << res << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}



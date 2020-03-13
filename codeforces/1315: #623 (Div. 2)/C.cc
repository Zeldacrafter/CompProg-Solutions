#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define endl '\n'

bitset<210> seen;
int nums[210];

void solve() {
    seen.reset();
    memset(nums, -1, sizeof(nums));

    int n, k;
    cin >> n;
    for(int i = 1; i < 2*n; i += 2) {
        cin >> k;
        seen[k] = true;
        nums[i] = k; 
    }

    for(int i = 1; i <= 2*n; i += 1) {
        if(seen[i]) continue;

        bool ok = false;
        for(int j = 2; j <= 2*n; j += 2) {
            if(nums[j] != -1) continue;

            if(nums[j - 1] < i) {
                nums[j] = i;
                seen[i] = true;
                ok = true;
                break;
            }
        }
        if(!ok) {
            cout << -1 << endl;
            return;
        }
    }


    cout << nums[1];
    FOR(i, 2, 2*n + 1)
        cout << ' ' << nums[i];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--)
        solve();
}

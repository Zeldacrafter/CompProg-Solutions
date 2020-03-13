#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define ROF(a, b, c) for(auto (a) = (b); (a) >= (c); --(a))
#define R0F(a, b) ROF(a, b, 0)
#define pb push_back
#define eb emplace_back
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define fst first
#define snd second
template <typename T>
void ckMin(T& a, T b) { a = min(a, b); }
template <typename T>
void ckMax(T& a, T b) { a = max(a, b); }

ll freq[1000010][27];
ll cnt[27];

void solve() {
    memset(cnt, 0, sizeof(cnt));

    int n, m;
    string s;
    cin >> n >> m >> s;

    F0R(i, n) {
        if(i) {
            F0R(j, 26)
                freq[i][j] = freq[i - 1][j];
        } else 
            F0R(j, 26)
                freq[0][j] = 0;
        freq[i][s[i] - 'a']++;
    }

    F0R(i, m) {
        int k;
        cin >> k;

        F0R(j, 26)
            cnt[j] += freq[k - 1][j];
    }

    F0R(i, 26)
        cnt[i] += freq[n - 1][i];

    cout << cnt[0];
    FOR(i, 1, 26)
        cout << ' ' << cnt[i];
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

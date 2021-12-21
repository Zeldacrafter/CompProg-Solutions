#include "../utils.cc"

typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<vvvvll> vvvvvll;

void solve() {
    int start1 = -1, start2 = -1;
    getInp([&](auto& cin, int) {
        string s; cin >> s >> s >> s >> s >> (start1 == -1 ? start1 : start2);
    });

    // p1, p2, s1, s2, turn -> amt
    vvvvvll dp(10, vvvvll(10, vvvll(21, vvll(21, vll(2, 0)))));
    dp[start1 - 1][start2 - 1][0][0][false] = 1;

    ll win1 = 0, win2 = 0;
    F0R(s1, 21) F0R(s2, 21) F0R(p1, 10) F0R(p2, 10) {
        FOR(d1, 1, 4) FOR(d2, 1, 4) FOR(d3, 1, 4) { // dice
            int rolled = d1 + d2 + d3;

            // turn player1
            int newP1 = (p1 + rolled) % 10;
            int newS1 = s1 + newP1 + 1;
            if(newS1 >= 21) win1 += dp[p1][p2][s1][s2][false];
            else dp[newP1][p2][newS1][s2][true] += dp[p1][p2][s1][s2][false];

            // turn player2
            int newP2 = (p2 + rolled) % 10;
            int newS2 = s2 + newP2 + 1;
            if(newS2 >= 21) win2 += dp[p1][p2][s1][s2][true];
            else dp[p1][newP2][s1][newS2][false] += dp[p1][p2][s1][s2][true];
        }
    }
    cout << max(win1, win2) << endl;
}


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
    F0R(s1, 21) F0R(s2, 21) F0R(p1, 10) F0R(p2, 10) F0R(turn, 2) {
        FOR(d1, 1, 4) FOR(d2, 1, 4) FOR(d3, 1, 4) { // dice
            int rolled = d1 + d2 + d3;

            int newP1 = (p1 + rolled*(1-turn)) % 10,
                newP2 = (p2 + rolled*turn) % 10,
                newS1 = s1 + (newP1 + 1)*(1-turn),
                newS2 = s2 + (newP2 + 1)*turn;
            (newS1 >= 21 ? win1 :
             newS2 >= 21 ? win2 : dp[newP1][newP2][newS1][newS2][!turn])
                += dp[p1][p2][s1][s2][turn];
        }
    }
    cout << max(win1, win2) << endl;
}


#include "../utils.cc"
typedef vector<vvi> vvvi;

bool wins(vvi& b) {
    F0R(i, 5) {
        bool r = true, c = true;
        F0R(j, 5) r &= b[i][j], c &= b[j][i];
        if(r || c) return true;
    }
    return false;
}

void solve() {
    vector<ll> nums;
    vvvi boards, boardsBool;
    getInp([&](auto& cin, int i) {
        if(!i) {
            // First row
            ll k; char c; cin >> k;
            do {
                nums.pb(k);
            } while(cin >> c >> k);
        } else {
            i--;
            if(i % 6 == 0) {
                // New board
                boards.pb(vvi(5, vi(5)));
                boardsBool.pb(vvi(5, vi(5)));
            } else {
                // Next row
                F0R(j, 5) cin >> boards.back()[i % 6 - 1][j];
            }
        }
    });

    ll res = 0;
    vi won(SZ(boards), false);
    for(ll n : nums) F0R(i, SZ(boards)) {
        // Mark number
        F0R(r, 5) F0R(c, 5)
            boardsBool[i][r][c] |= boards[i][r][c] == n;
        // Check won
        if(!won[i] && wins(boardsBool[i])) {
            ll unmarked = 0;
            F0R(r, 5) F0R(c, 5)
                unmarked += !boardsBool[i][r][c]*boards[i][r][c];
            
            res = unmarked * n;
            won[i] = true;
        }
    }
    cout << res << endl;
}


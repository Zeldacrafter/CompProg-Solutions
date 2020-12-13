#include "../template.cc"

void solve() {
    ll amt;
    cin >> amt;
    string s;
    cin >> s;
    vector<string> inp = split(s, ",");

    ll best = 1e9;
    ll bestB = -1;
    F0R(i, SZ(inp))
        if(inp[i] != "x") {
            ll val = stoi(inp[i]);
            ll left = amt % val;
            if (ckmin(best, left ? val - left : 0))
                bestB = val;
        }

    cout << best * bestB << endl;

}


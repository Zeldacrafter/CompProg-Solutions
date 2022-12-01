#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();
    ss.pb("");

    ll curr = 0;
    vector<ll> totals;
    for(string& s : ss) {
        if(s == "") {
            totals.pb(curr);
            curr = 0;
        } else {
            curr += stoll(s);
        }
    }
    sort(RALL(totals));

    cout << totals[0] + totals[1] + totals[2] << endl;
}


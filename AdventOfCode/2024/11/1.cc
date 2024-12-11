#include "../utils.cc"

ll calc(ll x, int amt) {
    if(!amt) return 1;
    if(!x) return calc(1, amt - 1);

    string st = to_string(x);
    if(SZ(st) % 2 == 0) 
        return calc(stoll(st.substr(0, SZ(st)/2)), amt - 1 ) 
             + calc(stoll(st.substr(SZ(st)/2)), amt - 1);

    return calc(x * 2024, amt - 1);
}

void solve() {
    vector<string> ss = split(getInp()[0], " ");

    ll res = 0;
    for(string& x : ss) res += calc(stoll(x), 75);
    cout << res << endl;
}


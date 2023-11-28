#include "../utils.cc"

void shuffle(vector<pair<ll, int>>& v, vector<ll>& inp) {
    F0R (i, SZ(v)) {
        auto it = find(ALL(v), mp(inp[i], i));
        ll j = it - v.begin();
        j += inp[i];
        v.erase(it);
        j = (j + SZ(v)) % SZ(v);
        v.insert(v.begin() + j, mp(inp[i], i));
    }
}

void solve() {
    vector<ll> inp;
    vector<pair<ll, int>> v;
    int idx = 0;

    getInp([&](auto& cin, int) {
        ll _k; cin >> _k; v.eb(_k, idx++); inp.pb(_k);
    });

    shuffle(v, inp);

    int i = 0;
    while(v[i].fi) ++i;
    ll res = 0;
    for(int j : {1000, 2000, 3000}) res += v[(i + j) % SZ(v)].fi;
    cout << res << endl;
}



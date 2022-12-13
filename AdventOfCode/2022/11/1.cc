#include "../utils.cc"

void solve() {

    vector<vector<ll>> qs;
    qs.pb({59, 65, 86, 56, 74, 57, 56});
    qs.pb({63, 83, 50, 63, 56});
    qs.pb({93, 79, 74, 55});
    qs.pb({86, 61, 67, 88, 94, 69, 56, 91});
    qs.pb({76, 50, 51});
    qs.pb({77, 76});
    qs.pb({74});
    qs.pb({86, 85, 52, 86, 91, 95});

    vi add = {0,  2, 1, 7, 0, 8, 0, 6};
    vi mul = {17, 1, 1, 1, 1, 1, 2, 1};
    vi sq  = {0,  0, 0, 0, 1, 0, 0, 0};

    vi div = {3, 13, 2, 11, 19, 17, 5, 7};

    vii next = { 
        {3, 6},
        {3, 0},
        {0, 1},
        {6, 7},
        {2, 5},
        {2, 1},
        {4, 7},
        {4, 5}
    };


    vector<ll> times(SZ(sq), 0);

    F0R(_, 20) {
        F0R(i, SZ(qs)) {
            times[i] += SZ(qs[i]);
            for (ll curr : qs[i]) {

                curr += add[i];
                curr *= mul[i];
                if(sq[i]) curr *= curr;
                curr /= 3;

                qs[curr % div[i] ? next[i].se : next[i].fi].pb(curr);
            }
            qs[i].clear();
        }
    }
    sort(RALL(times));
    cout << times[0] * times[1] << endl;

}

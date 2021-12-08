#include "../utils.cc"

typedef vector<vvi> vvvi;

vvi digits = {
    {0, 1, 2,    4, 5, 6}, 
    {      2,       5   }, 
    {0,    2, 3, 4,    6}, 
    {0,    2, 3,    5, 6}, 
    {   1, 2, 3,    5   }, 
    {0, 1,    3,    5, 6}, 
    {0, 1,    3, 4, 5, 6}, 
    {0,    2,       5   }, 
    {0, 1, 2, 3, 4, 5, 6}, 
    {0, 1, 2, 3,    5, 6}
};

vi getPerm(vvi& all) {
    vi perm(7); iota(ALL(perm), 0);
    do {
        bool ok = true;
        for (vi& v : all) {
            vi vPerm(SZ(v));
            F0R(i, SZ(v)) vPerm[i] = perm[v[i]];
            sort(ALL(vPerm));

            ok &= count(ALL(digits), vPerm);
            if(!ok) break;
        }
        if (ok) return perm;
    } while (next_permutation(ALL(perm)));

    assert(false);
    return vi();
}

int calc(vvi& r, const vi& perm) {
    int res = 0;
    for (vi& v : r) {
        F0R(i, SZ(v)) v[i] = perm[v[i]];
        sort(ALL(v));
        res = res*10 + distance(digits.begin(), find(ALL(digits), v));
    }
    return res;
}

void solve() {
    vvvi inp, inpR;
    getInp([&](auto& cin, int) {
        inp.eb(); inpR.eb();
        string s; bool outp = false;
        while(cin >> s) {
            if(s == "|") {
                outp = true;
            } else {
                inp.back().eb(ALL(s));
                if(outp) inpR.back().eb(ALL(s));
            }
        }
    });
    inp -= 'a'; inpR -= 'a';

    ll res = 0;
    F0R(i, SZ(inp)) res += calc(inpR[i], getPerm(inp[i]));
    cout << res << endl;
}

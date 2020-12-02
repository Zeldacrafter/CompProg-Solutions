#include "../template.cc"

void solve() {
    vi a;
    getInp([&](stringstream& cin, int i) {
            int k;
            cin >> k;
            a.pb(k);   
    });
    int n = SZ(a);

    F0R(i, n) 
        FOR(j, i + 1, n)
            if(a[i] + a[j] == 2020)
                cout << a[i]*a[j] << endl;
}

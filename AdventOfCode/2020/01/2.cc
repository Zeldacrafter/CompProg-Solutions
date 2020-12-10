#include "../template.cc"

void solve() {
    vi a;
    getInp([&](auto& cin, int i) {
            int k;
            cin >> k;
            a.pb(k);   
    });
    int n = SZ(a);

    F0R(i, n) 
        FOR(j, i + 1, n) 
            FOR(k, j + 1, n)
                if(a[i] + a[j] + a[k] == 2020)
                    cout << a[i]*a[j]*a[k] << endl;
}


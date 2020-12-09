#include "../template.cc"

const int OFFSET = 25;

void solve() {
    vector<ll> a;
    vector<string> ss = getInp([&](auto& cin, int) {
        int k;
        cin >> k;
        a.pb(k);
    });

    auto ok = [&](int i) {
        FOR(j, i - OFFSET, i)
            FOR(k, j + 1, i)
                if(a[i] == a[j] + a[k])
                    return true;
        return false;
    };

    FOR(i, OFFSET, SZ(a))
        if(!ok(i)) {
            cout << a[i] << endl;
            break;
        }
}


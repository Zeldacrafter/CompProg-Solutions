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

    ll bad = -1;
    FOR(i, OFFSET, SZ(a))
        if(!ok(i)) {
            bad = a[i];
            break;
        }

    F0R(i, SZ(a))
        FOR(j, i + 1, SZ(a))
            if(accumulate(a.begin() + i, a.begin() + j + 1, 0ll) == bad) {
                cout << *max_element(a.begin() + i, a.begin() + j + 1) + *min_element(a.begin() + i, a.begin() + j + 1) << endl;
                return;
            }
}


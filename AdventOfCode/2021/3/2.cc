#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();
    int n = SZ(ss[0]);

    auto calc = [&](auto f) {
        vector<string> rem(ALL(ss));
        F0R(i, n) if(SZ(rem) > 1) {
            ll cnt0 = 0, cnt1 = 0;
            for(string& s : rem) {
                if(s[i] == '0') cnt0++;
                if(s[i] == '1') cnt1++;
            }

            // rem.resize(remove_if(ALL(rem), [&](string& s) { return f(cnt0, cnt1) == (s[i] == '0'); }) - rem.begin());

            vector<string> v;
            for (auto& s : rem)
                if(f(cnt0, cnt1) == (s[i] == '0')) v.pb(s);
            rem = v;
        }
        return stoi(rem[0], nullptr, 2);
    };

    ll res1 = calc([](int a, int b) { return a > b; });
    ll res2 = calc([](int a, int b) { return a <= b; });
    cout << res1*res2<< endl;

}


#include "../utils.cc"

const array<string, 9> nums {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void solve() {
    vector<string> ss = getInp();

    ll res = 0;
    for(string& s : ss) {
        vi v;
        F0R(i, SZ(s)) {
            if(isdigit(s[i])) v.pb(s[i] - '0');
            F0R(j, SZ(nums)) if (s.substr(i, SZ(nums[j])) == nums[j]) v.pb(j + 1);
        }
        res += v.front()*10 + v.back();
    }
    cout << res << endl;
}


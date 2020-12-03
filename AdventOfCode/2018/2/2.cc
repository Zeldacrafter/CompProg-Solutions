#include "../template.cc"

void solve() {
    vector<string> ss = getInp();

    for(string& s1 : ss) 
        for(string& s2 : ss)
            if(s1 != s2) {
                int diff = 0;
                F0R(i, SZ(s1))
                    diff += s1[i] != s2[i];
                if(diff == 1) {
                    F0R(i, SZ(s1))
                        if(s1[i] == s2[i])
                            cout << s1[i];
                    cout << endl;
                    return;
                }
            }
}



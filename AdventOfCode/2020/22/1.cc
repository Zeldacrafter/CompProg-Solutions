#include "../template.cc"

void play(deque<int>& p1, deque<int>& p2) {
    while(SZ(p1) && SZ(p2)) {
        int curr1 = p1.front(); p1.pop_front();
        int curr2 = p2.front(); p2.pop_front();

        if(curr1 > curr2) {
            p1.pb(curr1);
            p1.pb(curr2);
        } else {
            p2.pb(curr2);
            p2.pb(curr1);
        }
    }
}

void solve() {
    vector<string> ss = getInp();

    deque<int> p1, p2;
    bool player2 = false;
    for(string& s : ss) {
        if(s == "")
            player2 = true;
        else if(isdigit(s[0]))
            (player2 ? p2 : p1).pb(stoi(s));
    }

    play(p1, p2);

    if(SZ(p2)) swap(p1, p2);

    ll score = 0;
    for(int i = 1; SZ(p1); ++i) {
        score += i*p1.back();
        p1.pop_back();
    }
    cout << score << endl;
}



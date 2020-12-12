#include "../template.cc"

using pt = complex<double>;

void solve() {
    vector<pair<char, int>> a;
    getInp([&](auto& cin, int) {
        char c;
        int x;
        cin >> c >> x;
        a.eb(c, x);
    });

    pt ship(0, 0), way(10, 1);

    for(auto [d, amt] : a) {
        if(d == 'F') {
            ship += (double)amt*way;
        } else if(d == 'S') {
            way += pt(0, -amt);
        } else if(d == 'E') {
            way += pt(amt, 0);
        } else if(d == 'W') {
            way += pt(-amt, 0);
        } else if(d == 'N') {
            way += pt(0, amt);
        } else if(d == 'R') {
            amt = 360 - (amt % 360);
            way *= polar(1.0, M_PI * (amt / 180.0));
        } else if(d == 'L') {
            way *= polar(1.0, M_PI * (amt / 180.0));
        }
    }
    cout << abs(ship.real()) + abs(ship.imag()) << endl;
}


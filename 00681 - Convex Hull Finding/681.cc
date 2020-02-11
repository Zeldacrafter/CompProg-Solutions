
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<int> ci;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pf push_front
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define SZ(x) (x).size()
#define ft front
#define bk back
#define ins insert
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) for (auto(a) = 0; (a) < (b); ++(a))
#define R0F(a, b) for (auto(a) = (b); (a) > 0; --(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))
#define ROFI(a, b) for (auto(a) = (b).rbegin(); (a) != (b).rend(); ++(a))
#define TRAV(a, b) for (auto&(a) : (b))
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define endl '\n'
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

double dir(ci p, ci q, ci r) {
    return real(p) * (imag(q) - imag(r)) 
         + real(q) * (imag(r) - imag(p)) 
         + real(r) * (imag(p) - imag(q));
}

bool ccw(ci p, ci q, ci r) {
    return dir(p, q, r) > 0;
}

bool cw(ci p, ci q, ci r) {
    return dir(p, q, r) < 0;
}

void convexHull(vector<ci>& pts) {
    // Assume that pts[0] != pts[SZ(pts) - 1]
    if(!SZ(pts)) return;
    sort(ALL(pts), [](const ci& a, const ci& b) {
        if(real(a) != real(b))
            return real(a) < real(b);
        else
            return imag(a) < imag(b);
    });

    ci fst = pts[0];
    ci lst = pts[SZ(pts) - 1];
    vector<ci> up, down;
    up.pb(fst); down.pb(fst);

    for(ci p : pts) {
        if(p == lst || cw(fst, p, lst)) {
            while(SZ(up) >= 2 && !cw(up[SZ(up) - 2], up[SZ(up) - 1], p))
                up.pop_back();
            up.pb(p);
        }
        if(p == lst || ccw(fst, p, lst)) {
            while(SZ(down) >= 2 && !ccw(down[SZ(down) - 2], down[SZ(down) - 1], p))
                down.pop_back();
            down.pb(p);
        }
    }

    pts = vector<ci>(down);
    R0F(i, SZ(up) - 2)
        pts.pb(up[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    cout << tc << endl;
    while(tc--) {
        int n;
        cin >> n;

        vector<ci> pts;
        F0R(i, n) {
            int x, y;
            cin >> x >> y;
            pts.eb(x, y);
        }
        pts.pop_back();

        convexHull(pts);

        int index = 0;
        F0R(i, SZ(pts))
            if(imag(pts[index]) > imag(pts[i]) || (imag(pts[index]) == imag(pts[i]) && real(pts[index]) > real(pts[i])))
                index = i;

        cout << SZ(pts) + 1 << endl;
        F0R(i, SZ(pts)) {
            int j = (index + i) % SZ(pts);
            cout << real(pts[j]) << ' ' << imag(pts[j]) << endl;
        }
        cout << real(pts[index]) << ' ' << imag(pts[index]) << endl;

        if(tc) {
            cout << -1 << endl;
            int tmp;
            cin >> tmp;
            assert(tmp == -1);
        }
    }
    return 0;
}


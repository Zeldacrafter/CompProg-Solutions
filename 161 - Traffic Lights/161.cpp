#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (x).size()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) for (auto(a) = 0; (a) < (b); ++(a))
#define R0F(a, b) for (auto(a) = (b); (a) >= 0; --(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))
#define ROFI(a, b) for (auto(a) = (b).rbegin(); (a) != (b).rend(); ++(a))
#define TRAV(a, b) for (auto &(a) : (b))
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t &a, const t &b) {
  return a > b ? a = b, true : false;
}
template <typename t> bool ckmax(t &a, const t &b) {
  return a < b ? a = b, true : false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(1) {
        vi data;
        while(1) {
            int k;
            cin >> k;

            if(!k) break;
            data.pb(k);
        }
        
        if(data.empty()) break;
        // 53 54 55 68 20 0
        sort(ALL(data), greater<int>());

        int t = data[SZ(data) - 1]*2;
        bool found = false;
        while(!found && t <= 18000) {
            bool valid = true;
            for(int n : data) {
                bool isIn = (t/n % 2 == 0) && (t % n < n - 5); 
                if(!isIn) {
                    t += n - t % n + (t/n % 2 == 0 ? n : 0);
                    valid = false;
                    break;
                }
            }
            if(valid)
                found = true;
        }

        if(found) {
            int s = t % 60;
            t /= 60;
            int m = t % 60;
            t /= 60;
            cout << setfill('0') << setw(2) << t << ':' << setfill('0') << setw(2) << m << ':' << setfill('0') << setw(2) << s << endl;
        } else
            cout << "Signals fail to synchronise in 5 hours\n";
    }
  
    return 0;
}

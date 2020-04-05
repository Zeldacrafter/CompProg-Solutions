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
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pf push_front
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ge(a, b) get<(b)>((a))
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmin(t& a, const t& b) {return a > b ? a = b, true : false;}
template <typename t> bool ckmax(t& a, const t& b) {return a < b ? a = b, true : false;}

int B;
bool k, k2;
char c;
bitset<110> bits;
void rev() {
    for(int i = 1; i < B - i + 1; ++i) {
        bool b = bits[i];
        bits[i] = bits[B - i + 1];
        bits[B - i + 1] = b;
    }
}

void solve() {
    bits.reset();
    int ok = 0;
    int same = 0, diff = 0;
    for(int q = 1;; q += 2) {
        if(q != 1 && q % 10 == 1) {
            assert(same || diff);

            cout << (same ? same : 1) << endl; cout.flush();
            cin >> k;
            cout << (diff ? diff : 1) << endl; cout.flush();
            cin >> k2;

            if(same && diff) {
                if(bits[diff] == k2) {
                    // Both or nothing.
                    if(bits[same] != k) {
                        bits.flip();
                        rev();
                    }
                } else {
                    // either flip or reverse
                    if(bits[same] == k)
                        rev();
                    else
                        bits.flip();
                }
            } else if(same) {
                // reverse doesnt do anything.
                if(bits[same] != k)
                    bits.flip();
            } else if(diff) {
                // flip and rev are same
                if(bits[diff] != k2)
                    bits.flip();
            }
        } else {
            cout << ++ok << endl; cout.flush();
            cin >> k;
            cout << B - ok + 1 << endl; cout.flush();
            cin >> k2;

            bits[ok] = k;
            bits[B - ok + 1] = k2;

            if(!same && bits[ok] == bits[B - ok + 1])
                same = ok;
            if(!diff && bits[ok] != bits[B - ok + 1])
                diff = ok;
        }
        
        if(2*ok >= B && left) {
            FOR(i, 1, B + 1)
                cout << bits[i];
            cout << endl; cout.flush();

            cin >> c; assert(c == 'Y');
            return;
        }
    }
}

int main() {
    int tc;
    cin >> tc >> B;

    while(tc--)
        solve();
}

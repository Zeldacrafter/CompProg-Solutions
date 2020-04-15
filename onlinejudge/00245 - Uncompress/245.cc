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
#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
if (DEBUG) std::cerr

int main() {

    string inp;
    while(1) {
        char c = getchar();
        if(c == '0' && (!SZ(inp) || !isdigit(inp[SZ(inp) - 1])))
            break;
        inp += c;
    }
    int n = SZ(inp);

    vector<string> text;
    string res, s;
    for(int i = 0; i < n; ) {
        while(i < n && isalpha(inp[i]))
            s.pb(inp[i++]);
        if(SZ(s)) {
            text.pb(s);
            res += s;
            s.clear();
        }

        while(i < n && isdigit(inp[i]))
            s.pb(inp[i++]);
        if(SZ(s)) {
            int offset = stoi(s);
            string next = text[SZ(text) - offset];

            text.erase(text.end() - offset);
            text.pb(next);

            res += next;
            s.clear();
        }

        while(i < n && !isalpha(inp[i]) && !isdigit(inp[i]))
            res += inp[i++];
    }
    cout << res;
}


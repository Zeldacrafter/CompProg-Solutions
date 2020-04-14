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
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);

    int p, g;
    cin >> p >> g;

    map<string, int> perc;
    F0R(i, p) {
        string s;
        double d;
        cin >> s >> d;
        perc[s] = (int) (d*10);
    }

    FOR(i, 1, g + 1) {
        int sum = 0, guess;
        string s;
        char op, op2;

        do {
            cin >> s >> op;
            sum += perc[s];
        } while(op == '+');

        op2 = getchar();
        cin >> guess;
        guess *= 10;

        bool b;
        if(op == '>')
            b = op2 == '=' ? sum >= guess : sum > guess;
        else if (op == '<')
            b = op2 == '=' ? sum <= guess : sum < guess;
        else
            b = guess == sum;
        cout << "Guess #" << i << " was " << (b ? "correct" : "incorrect") << '.' << endl;;
    }
}


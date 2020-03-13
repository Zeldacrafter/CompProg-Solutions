#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define SZ(x) (x).size()
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()

int n, len;
bool isPalin(string& a, string& b) {
    F0R(i, SZ(a))
        if(a[i] != b[SZ(a) - 1 - i])
            return false;
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> len;

    vector<string> strings;
    string left = "";
    string mid = "";
    string right = "";
    F0R(i, n) {
        string s;
        cin >> s;
    
        if(mid == "" && isPalin(s, s)) {
            mid = s;
            continue; 
        }

        bool found = false;
        F0R(j, SZ(strings)) {
            if(isPalin(s, strings[j])) {
                left += s;
                right = strings[j] + right;
                strings.erase(strings.begin() + j);
                found = true;
                break;
            }
        }

        if(!found)
            strings.pb(s);
    }

    string s = left + mid + right;
    cout << SZ(s) << endl << s << endl;
}

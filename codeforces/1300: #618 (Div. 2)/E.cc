#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR((a), 0, (b))
#define se second
#define fi first

ll sums[1000005];
double ans[1000005] = {0.0};

double mean(const ii& a) {
    return (double)(sums[a.se] - sums[a.fi]) / (a.se - a.fi);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    sums[0] = 0;
    F0R(i, n) {
        int k;
        cin >> k;
        sums[i + 1] = k + sums[i];
    }

    stack<ii> s;
    F0R(i, n) {
        s.emplace(i, i + 1);

        while(s.size() > 1) {
            ii a = s.top();
            s.pop();
            ii b = s.top();

            if(mean(b) < mean(a)) {
                s.push(a);
                break;
            }
            s.pop();

            s.emplace(b.fi, a.se);
        }
    }

    while(!s.empty()) {
        ii a = s.top();
        s.pop();

        double x = mean(a);
        FOR(k, a.fi, a.se)
            ans[k] = x;
    }

    cout << setprecision(13);
    F0R(i, n)
        cout << ans[i] << '\n';
}

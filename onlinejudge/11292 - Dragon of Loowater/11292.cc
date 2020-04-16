#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    while(1) {
        cin >> n >> m;
        if(!n && !m)
            break;

        vi head(n), knight(m);
        F0R(i, n) cin >> head[i];
        F0R(i, m) cin >> knight[i];
        sort(ALL(head));
        sort(ALL(knight));

        int res = 0;
        int h, k;
        for(h = 0, k = 0; h < n && k < m; h++, k++) {
            while(k < m && head[h] > knight[k])
                k++;
            if(k > m)
                continue;
            res += knight[k];
        }
        if(h < n)
            cout << "Loowater is doomed!" << endl;
        else
            cout << res << endl;
    }

}


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define SZ(x) (x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define CLR(a, b) memset((a), (b), sizeof((a)))
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }

const int MAXA = 1e6;

vii adj[MAXA];
vi primes;
int p[MAXA], dist[MAXA], nextPrime[MAXA + 1];

int bfs(int start) {
    CLR(p, -1);
    CLR(dist, -1);

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int res = 1e9;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto [v, id] : adj[curr]) {
            if(id == p[curr])
                continue;

            if(dist[v] >= 0) {
                ckmin(res, dist[curr] + dist[v] + 1);
                continue;
            }

            dist[v] = dist[curr] + 1;
            p[v] = id;
            q.push(v);
        }

    }

    return res;
}

void sieve() {
    primes.pb(1);
    nextPrime[1] = 1;
    FOR(i, 2, MAXA + 1) {
        if(!nextPrime[i]) {
            primes.pb(i);
            for(int j = i; j <= MAXA; j += i)
                nextPrime[j] = i;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    sieve();
    int n;
    cin >> n;

    int edgeCnt = 0;
    F0R(i, n) {
        int k;
        cin >> k;

        int fac1 = nextPrime[k];
        if(fac1 != 1) {
            bool par = false;
            while(k % fac1 == 0) {
                par = !par;
                k /= fac1;
            }
            if(!par)
                fac1 = 1;
        }

        int fac2 = nextPrime[k];
        if(fac2 != 1) {
            bool par = false;
            while(k > 1) {
                par = !par;
                k /= fac2;
            }
            if(!par)
                fac2 = 1;
        }

        adj[fac1].eb(fac2, edgeCnt);
        adj[fac2].eb(fac1, edgeCnt);
        edgeCnt++;
    }

    int res = 1e9;
    for(int i : primes) {
        if(i * i > MAXA) break;
        if(!SZ(adj[i])) continue;
        ckmin(res, bfs(i));
    }

    if(res == (int)1e9)
        cout << -1 << endl;
    else
        cout << res << endl;
}





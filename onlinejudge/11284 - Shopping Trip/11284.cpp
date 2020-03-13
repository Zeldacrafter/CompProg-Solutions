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
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
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

#define HOME2 51

array<array<double, 55>, 55> adj;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--) {

        int stores, roads;
        cin >> stores >> roads;

        F0R(i, stores + 1)
            adj[i].fill(INFINITY);
        
        F0R(i, roads) {
            int a, b;
            double c;
            cin >> a >> b >> c;
            ckmin(adj[a][b], c);
            ckmin(adj[b][a], c);
        }

        F0R(i, stores + 1)
            adj[i][i] = 0; // init
        adj[HOME2][HOME2] = 0;

        int dvdAmt;
        cin >> dvdAmt;
        vector<pair<int, ld>> dvds;
        F0R(i, dvdAmt) {
            int pos;
            ld price;
            cin >> pos >> price;
            dvds.eb(pos, price);
        }

        // Floyd warshall
        F0R(k, stores + 1) 
            F0R(i, stores + 1)
                F0R(j, stores + 1)
                    ckmin(adj[i][j], adj[i][k] + adj[k][j]);

        // Dijkstra
        map<ii, ld> dist;

        auto cmp = [](const tuple<int, int, ld>& a, const tuple<int, int, ld>& b) {
            return get<2>(a) > get<2>(b);
        };
        priority_queue<tuple<int, int, ld>, vector<tuple<int, int, ld>>, decltype(cmp)> q(cmp); 

        q.emplace(0, 0, 0.0);
        dist[mp(0, 0)] = 0;
        
        while(!q.empty()) {
            auto curr = q.top();
            q.pop();

            int node = get<0>(curr);
            int cds = get<1>(curr);
            ld price = get<2>(curr);

            if(node == HOME2) {
                if(cds) {
                    ld totalCost = accumulate(ALL(dvds), 0.0, [](const ld& a, const pair<int, ld>& b) { return a + b.se; });
                    cout << "Daniel can save $" << fixed << setprecision(2) << totalCost - price << endl;
                }
                else
                    cout << "Don't leave the house\n";
                break;
            }

            if(dist[mp(node, cds)] < price)
                continue; // Prev path is better

            // Drive to next store
            ld sum = 0;
            FOR(j, 0, SZ(dvds)) {
                pair<int, ld> storeNode = dvds[j];
                if((1 << j) & cds)
                    continue; // Store already collected

                sum += storeNode.se;

                // Check if path was never found before or is better
                ld newPrice = adj[node][storeNode.fi] + price;

                auto it = dist.find(mp(storeNode.fi, cds | (1 << j)));
                if(it == dist.end() || it->second > newPrice) {
                    dist[mp(storeNode.fi, cds | (1 << j))] = newPrice;
                    q.emplace(storeNode.fi, cds | (1 << j), newPrice);
                }

            }

            // drive home
            ld newPrice = sum + price + adj[node][0];
            auto it = dist.find(mp(HOME2, cds));
            if(it == dist.end() || it->second > newPrice) {
                dist[mp(HOME2, cds)] = newPrice;
                q.emplace(HOME2, cds, newPrice);
            }

        }
    }

    return 0;
}

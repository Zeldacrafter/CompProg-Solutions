#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))

int main() {

    char buffer[10];
    queue<pair<int, int>> left;
    queue<pair<int, int>> right;


    int tc;
    scanf("%d", &tc);

    while(tc--) {
        vector<pair<int, int>> delivered;
        
        int capacity;
        int timeAcross;
        int carC;
        scanf("%d %d %d", &capacity, &timeAcross, &carC);

        // Input
        FOR(i, 0, carC) {
            int time;
            scanf("%d %10s", &time, buffer);
            switch(buffer[0]) {
                case 'l':
                    left.push({i, time});
                    break;
                case 'r':
                    right.push({i, time});
                    break;
                default:
                    assert(false);
                    break;
            }
        }
        
        int timePassed = 0;
        bool ferryIsLeft = true;
        while(left.size() > 0 || right.size() > 0) {
            
            // Wait if nobody there.
            if((left.size() == 0 || left.front().second > timePassed) && 
               (right.size() == 0 || right.front().second > timePassed)) {
                timePassed += 1;
                continue;
            }

            // Carry max possible amount across.
            FOR(i, 0, capacity) {
                if(ferryIsLeft) {
                    if(left.size() == 0 || left.front().second > timePassed) break;
                    delivered.push_back({left.front().first, timePassed + timeAcross});
                    left.pop();
                } else {
                    if(right.size() == 0 || right.front().second > timePassed) break;
                    delivered.push_back({right.front().first, timePassed + timeAcross});
                    right.pop();
                }
            }
            timePassed += timeAcross;
            ferryIsLeft = !ferryIsLeft;
        }

        // Output in same order as input
        sort(delivered.begin(), delivered.end(), 
            [](pair<int, int> a, pair<int, int> b) {
                return a.first <= b.first;
            });

        FOR(i, 0, delivered.size())
            printf("%d\n", delivered[i].second);
        if(tc) printf("\n");
    }

    return 0;
}

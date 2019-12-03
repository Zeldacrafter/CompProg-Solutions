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

int wantedOrder[1010];

int main() {

    for(int tc = 0;; tc++) {
        int wagons;
        scanf("%d", &wagons);
        if(!wagons) break;

        for(int tc2 = 0;; tc2++) {
            scanf("%d", wantedOrder);
            if(!wantedOrder[0]) break;
            FOR(i, 1, wagons) scanf("%d", wantedOrder + i);

            int nextWantedIndex = 0;
            int nextTrain = 1;
            stack<int> station;
            while(nextTrain <= wagons) {
                if(nextTrain == wantedOrder[nextWantedIndex]) {
                    nextTrain++;
                    nextWantedIndex++;
                    while(!station.empty() && station.top() == wantedOrder[nextWantedIndex]) {
                        station.pop();
                        nextWantedIndex++;
                    }
                } else {
                    station.push(nextTrain++);
                }
            }
            
            if(station.empty()) 
                printf("Yes\n");
            else 
                printf("No\n");
        }
        printf("\n");
    }

    return 0;
}

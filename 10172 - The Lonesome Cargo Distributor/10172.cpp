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

class myqueue : public queue<int> {
    public:
    void clear() { c.clear(); }
};
class mystack : public stack<int> {
    public:
    void clear() { c.clear(); }
};

myqueue queues[110];
mystack carried;

void debugOutput(int queueAmount, int currStation, int time) {
    printf("Finished station %d after %d min\n", currStation, time);
    printf("Stack: %ld\n", carried.size());
    FOR(i, 0, queueAmount) {
        printf("Queue %d: %ld\n", i, queues[i].size());
    }
    printf("\n");
}

bool done(int queueAmount) {
    if(!carried.empty()) return false;
    FOR(i, 0, queueAmount)
        if(!queues[i].empty())
            return false;
    return true;
}

int main() {
    
    int tc;
    scanf("%d", &tc);

    while(tc--) {

        int stations;
        int cargoCapacity;
        int queueCapacity;
        scanf("%d %d %d", &stations, &cargoCapacity, &queueCapacity);

        FOR(i, 0, stations) queues[i].clear();

        FOR(i, 0, stations) {
            int nrQueued;
            scanf("%d", &nrQueued);
            FOR(j, 0, nrQueued) {
                int cargoNr;
                scanf("%d", &cargoNr);
                queues[i].push(cargoNr - 1); //-1 because stations are 1-indexed in input
            }
        }

        int time = 0;
        int pos = 0;
        carried.clear();
    
        while(true) {

            // Unload from cargo
            while(!carried.empty()) {
                if(carried.top() != pos) {
                    // Check if queue full.
                    if(queues[pos].size() >= queueCapacity) break; 
                    queues[pos].push(carried.top());
                }
                carried.pop();
                time++;
            }

            // load from queue
            while(carried.size() < cargoCapacity && !queues[pos].empty()) {
                carried.push(queues[pos].front());
                queues[pos].pop();
                time++;
            }

            //debugOutput(stations, pos, time);

            if(done(stations)) break;

            // Go to next if not done.
            pos = (pos + 1 == stations) ? 0 : (pos + 1);
            time += 2;
        }
        printf("%d\n", time);

    }

    return 0;
}

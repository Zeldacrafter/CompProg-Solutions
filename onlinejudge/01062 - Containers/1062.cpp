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

class mystack : public stack<char> {
    public:
    void clear() {
        c.clear();
    }
};

char line[1010];
mystack stacks[27];

int main() {

    for(int tc = 1; ; ++tc) {
        scanf("%1010s", line);
        if(line[0] == 'e') break;
        int len = strlen(line);

        int stackCount = 0;
        if(len > 0) {
            FOR(i, 0, 27) stacks[i].clear();

            char lastUsedStack = stackCount;
            stacks[stackCount].push(line[0]);
            stackCount++;

            FOR(i, 1, len) {

                // Check if we can just perfectly stack it.
                int sameExists = false;
                FOR(j, 0, stackCount) {
                    if(stacks[j].top() == line[i]) {
                        sameExists = true;
                        break;
                    }
                }

                // If we can perfectly stack it we dont need to do anything.
                if(!sameExists) {

                    // Check if we can find any stack where we can stack our char on.
                    // Perferably one that is close to the new char.
                    // So if line[i] = F we prefer a stack (E line[i]) to (A line[i]).
                    char min = 100;
                    int maxIndex = -1;
                    bool exists = false;
                    FOR(j, 0, stackCount) {
                        if(stacks[j].top() < min && 
                           stacks[j].top() > line[i]) {
                            min = stacks[j].top();
                            maxIndex = j;
                            exists = true;
                        }
                    }

                    if(exists) {
                        // Found a valid stack. Just push it on.
                        stacks[maxIndex].push(line[i]);
                        lastUsedStack = maxIndex;
                    } else {
                        // No stack exists. Create a new one.
                        stacks[stackCount].push(line[i]);
                        stackCount++;
                    }

                }
            }
        }

        printf("Case %d: %d\n", tc, stackCount);
    }

    return 0;
}

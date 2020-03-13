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

char sBuffer[30];
bitset<(1 << 30)> t = {};
bitset<(1 << 30)> f = {};

bool solve(int n) {
    // We already know that we can fully pop this.
    if(t[n]) return true;
    // We already know that we can't fully pop this.
    if(f[n]) return false;

    // The leftmost 1 indicates the amount of groups.
    // If the k'th bit is the leftmost one that is set then
    // all k-1 bits following it represent a group
    int start = 25;
    while(!((1 << (start + 1)) & n)) {
        start--;
    }

    for(int i = start; i >= 0; --i) {
        // Go through all groups (bits) and try to pop them one after another.
        if((1 << i) & n) {
            // We can only pop the group corresponding to this bit if it is set
            // (given from construction)
            if(i == start) {
                // Pop the leftmost group (which corresponds to the highest bit).
                // Since no groups can merge when popping
                // a bit from the end we can just unset the bit
                // and leave all other groups as they were.

                // We need to unset the i'th bit and move the start bit 
                // one to the left which is the i'th position.
                // So in sum only the (i+1)'th bit gets unset.
                int unsetBit = n & ~(1 << (i + 1));
                if (solve(unsetBit)) {
                    t[n] = true;
                    return true;
                }
            } else if (i == 0) {
                // Pop the rightmost group (corresponding to the lowest bit)
                // This just corresponds the shifting everything one right since:
                // - No groups can be merged when popping from end of the string
                // - The start needs to be moved 1 to the right
                int shiftOne = n >> 1;
                if(solve(shiftOne)) {
                    t[n] = true;
                    return true;
                }
            } else {
                // Pop the i'th group (which is somewhere in the middle).

                // This means that we need to merge the (i+1)'th and (i-1)'th
                // group. This merged group can now be popped for sure because
                // it consists of 2+ members.
                int mergedGroupBit = 1 << (i - 1);
                
                // Keep all bits that are to the right of the merged group the same.
                int rightOfGroup = n & ( (1 << (i - 1) ) - 1);
                
                // Keep all bits to the left of the merged group and shift them over by 2:
                // - One for the bit that was removed
                // - One for the group that was merged (2 bits became one)
                int leftOfGroup = (n & ~((1 << (i + 2)) - 1)) >> 2;
                
                if (solve(leftOfGroup | mergedGroupBit | rightOfGroup)) {
                    t[n] = true;
                    return true;
                }
            }
        }
    }

    // Did not find a way to fully pop this.
    f[n] = true;
    return false;
}

int main() {
    int tc;
    scanf("%d", &tc);

    // The number is encoded in the following way:
    // We only differentiate between poppable groups and un-poppable groups
    // If the n'th group is poppable the n'th bit is set.
    // If the n'th group is not poppable the n'th bit is not set.
    // There is a leftmost bit that is always set. It marks the beginning of the groups.
    // Example:  b a bbb aaa bb
    //      ->   0 0  1   1  1
    //      -> (100111)_2 = 39

    // We know that an empty string is reduceable.
    t[1] = true;

    // String with only unpoppable groups can not be reduced.
    for(int i = 1; i < 30; ++i) {
        f[1 << i] = true;
    }

    while(tc--) {
        scanf(" %30s", sBuffer);
        int len = strlen(sBuffer);
        
        int encodedStr = 0;
        
        char currChar = sBuffer[len - 1];
        int totalGroups = 0;
        int currGroupLen = 1;
        for(int i = len - 2; i >= 0; --i) {
            if(sBuffer[i] == currChar) {
                // Group still continuing
                currGroupLen++;
            } else {
                // Only set bit if group is poppable
                if(currGroupLen > 1) {
                    encodedStr |= 1 << totalGroups;
                }
                totalGroups++;
                
                currChar = sBuffer[i];
                currGroupLen = 1;
            }
        }
        
        // Process last group
        if(currGroupLen > 1) {
            encodedStr |= 1 << totalGroups;
        }
        totalGroups++;

        // Bit indicating start
        encodedStr |= 1 << totalGroups;

        printf("%d\n", solve(encodedStr));
    }

    return 0;
}

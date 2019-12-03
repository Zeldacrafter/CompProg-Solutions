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

#define IN true
#define OUT false

char from[100000];
char to[100000];
int len;


void getCombinations(deque<char> s, deque<bool> op, int nextElem, int nextWanted) {

    if(nextElem >= len) {
        // Remove remaining elements on stack that match
        while(!s.empty() && nextWanted < len && s.front() == to[nextWanted]) {
            nextWanted++;
            op.push_back(OUT);
            s.pop_front();
        }

        // We are done.
        if(s.empty() && nextWanted == len) {
            // Success.
            while(!op.empty()) {
                printf("%c", op.front() == IN ? 'i' : 'o');
                if(op.size() != 1) printf(" ");
                op.pop_front();
            }
            printf("\n");
        }
        return;
    }

    // Not done yet.

    // Push next element
    s.push_front(from[nextElem]);
    op.push_back(IN);
    getCombinations(s, op, nextElem + 1, nextWanted);
    op.pop_back();
    s.pop_front();

    // Check if we can pop from stack.
    if(!s.empty() && to[nextWanted] == s.front()) {
        char top = s.front();
        s.pop_front();
        op.push_back(OUT);
        getCombinations(s, op, nextElem, nextWanted + 1);
        //s.push_front(top);
        //op.pop_back();
    }
}

int main() {

    while(scanf(" %100000s", from) != EOF) {
        scanf(" %100000s", to);
        len = strlen(from);

        printf("[\n");
        if(strlen(to) == len) {
            deque<char> s;
            deque<bool> op;
            getCombinations(s, op, 0, 0);
        }
        printf("]\n");
    }

    return 0;
}

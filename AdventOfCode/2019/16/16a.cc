#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;

vector<int> arr;
int pattern[] = {0, 1, 0, -1};

void phase() {
    vector<int> res;

    // Calculate every digit seperatly.
    FOR(i, 1U, arr.size() + 1) { // Start with 1 because the
                                 // pattern-phase length is 1-indexed

        int digit = 0;
        for(unsigned int j = 0, patternPos = 0; j < arr.size(); ++j) {

            // j + 1 because we skip the first one
            if((j + 1) % i == 0)
                patternPos = (patternPos + 1) & 3;

            digit += arr[j] * pattern[patternPos];
        }
        res.push_back(abs(digit) % 10);
    }

    arr = res;
}

int main() {

    char c;
    while(scanf("%c", &c) != EOF)
        if(c >= '0' && c <= '9')
            arr.push_back(c - '0');

    // Just simulate the process.
    FOR(i, 0, 100)
        phase();

    FOR(i, 0U, 8)
        printf("%d", arr[i]);
    printf("\n");

    return 0;
}
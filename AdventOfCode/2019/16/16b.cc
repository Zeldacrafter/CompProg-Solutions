#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;

int main() {

    vector<int> inp;
    char c;
    while(scanf("%c", &c) != EOF)
        if(c >= '0' && c <= '9')
            inp.push_back(c - '0');

    vector<int> arr;
    FOR(i, 0, 10000)
      arr.insert(arr.end(), inp.begin(), inp.end());

    // Calculate message offset
    unsigned int offset = 0;
    FOR(i, 0, 7)
        offset += inp[i] * pow(10, 6 - i);

    // Key insight:
    // The offset is greater than half the array length.
    // For the calculation of every element in the second half 
    // the following holds true:
    // The coefficient of the numbers in the first half is all 0.
    // The coefficient of the numbers in the second half is all 1.
    assert(offset > arr.size() / 2);

    FOR(i, 0, 100) {
        // Build the sum of all relevant elements
        int sum = 0;
        FOR(j, offset, arr.size())
            sum += arr[j];

        // Every element is equal to the sum of all
        // the elements with a index greater or equal
        // to its own.
        FOR(j, offset, arr.size()) {
            int n = sum;
            sum -= arr[j];
            arr[j] = abs(n) % 10;
        }
    }

    FOR(i, offset, offset + 8)
        printf("%d", arr[i]);
    printf("\n");

    return 0;
}
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

    vi list;
    int nextElem;
    while(scanf(" %d", &nextElem) != EOF) {
        list.push_back(nextElem);

        if(list.size() & 1) {
            int mid = list.size()/2;

            nth_element(list.begin(), list.begin() + mid, list.end());
            int elem = list[mid];

            printf("%d\n", elem);
        } else {
            int midL = list.size()/2 - 1;
            int midR = list.size()/2;
            
            nth_element(list.begin(), list.begin() + midL, list.end());
            int elemL = list[midL];
            nth_element(list.begin(), list.begin() + midR, list.end());
            int elemR = list[midR];

            printf("%d\n", (elemL + elemR)/2);
        }
    }

    return 0;
}

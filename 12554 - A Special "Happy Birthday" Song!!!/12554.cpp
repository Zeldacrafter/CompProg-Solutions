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

char buffer[110];
string names[110];
string song[] = {
    "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"
};

int main() {

    int persons;
    scanf("%d", &persons);

    FOR(i, 0, persons) {
        scanf("%110s", buffer);
        names[i] = buffer;
    }

    int index = 0;
    while(index % 16 != 0 || index < persons) {
        printf("%s: %s\n", names[index % persons].c_str(), song[index % 16].c_str());
        index++;
    }

    return 0;
}

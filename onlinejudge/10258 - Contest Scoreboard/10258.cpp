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

struct person {
    int id;
    bool active;
    bool correct[10];
    int correctAmount;
    int incorrect[10];
    int time;
};

char buffer[100] = {};
person persons[110] = {};

int main() {

    int tc;
    scanf("%d\n\n", &tc);

    for(int test = 0; test < tc; test++) {

        memset(persons, 0, sizeof(person)*110);
        int id;
        int probId;
        int time;
        char classicfication;

        for(char *c = fgets(buffer, 100, stdin);
                  c != NULL && buffer[0] != '\n';
                  c = fgets(buffer, 100, stdin)) {

            sscanf(buffer, " %d %d %d %c", &id, &probId, &time, &classicfication);


            persons[id].id = id;
            persons[id].active = true;
            switch(classicfication) {
                case 'C':
                    if(!persons[id].correct[probId]) {
                        persons[id].time += time + 20*persons[id].incorrect[probId];
                        persons[id].correct[probId] = true;
                        persons[id].correctAmount++;
                    }
                    break;
                case 'I':
                    persons[id].incorrect[probId]++;
                    break;
            }

        }

        sort(persons, persons + 101, [](const person& a, const person& b) {

            if(a.id == b.id)
                return false;

            if(!a.active) return true;
            if(!b.active) return false;

            if(a.correctAmount != b.correctAmount)
                return a.correctAmount > b.correctAmount;

            if(a.time != b.time) 
                return a.time < b.time;

            return a.id < b.id;
        });

        for(auto p : persons) {
            if(p.active)
                printf("%d %d %d\n", p.id, p.correctAmount, p.time);
        }
        if(test != tc-1) printf("\n");
    }

    return 0;
}

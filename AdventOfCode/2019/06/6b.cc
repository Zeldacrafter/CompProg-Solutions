#include <bits/stdc++.h>
using namespace std;

#define START "YOU"
#define ROOT "COM"
#define DEST "SAN"

int main() {

    map<string, string> parent;

    char planet1[5];
    char planet2[5];
    while(scanf(" %5[A-Z1-9])%5[A-Z1-9]", planet1, planet2) != EOF)
        parent[string(planet2)] = string(planet1);

    // Get the distance to every node on the START -> ROOT path
    map<string, int> distToStart;
    string currNode = parent[START]; // Starting at the orbit of the start node
    distToStart[START] = 0;
    while(currNode != ROOT) {
        distToStart[parent[currNode]] = 1 + distToStart[currNode];
        currNode = parent[currNode];
    }

    // Go up the tree till we find a node that 
    // is also on the path from START to ROOT.
    currNode = parent[DEST]; // Ending at the orbit of our destination node
    int dist = 0;
    while(distToStart.find(currNode) == distToStart.end()) {
        currNode = parent[currNode];
        dist++;
    }

    printf("%d\n", dist + distToStart[currNode]);
}
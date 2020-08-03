#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> children;

int countOrbits(string node) {
    // Simple traversal of all children.
    int orbits = children[node].size(); // Direct connections
    for(string child : children[node])
        orbits += countOrbits(child);   // Indirect connections
    return orbits;
}

int main() {


    set<string> nodes;

    char planet1[5];
    char planet2[5];
    while(scanf(" %5[A-Z1-9])%5[A-Z1-9]", planet1, planet2) != EOF) {
        children[string(planet1)].push_back(string(planet2));
        nodes.insert(string(planet1));
    }

    int orbits = 0;
    for (string node : nodes)
        orbits += countOrbits(node);

    printf("%d\n", orbits);
}
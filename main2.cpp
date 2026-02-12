#include <iostream>
#include <vector>
using namespace std;

// Ajoute une arête non orientée (u <-> v)
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

// Q5 : deux sommets sont-ils adjacents ?
bool is_adj_list(const vector<vector<int>>& adjList, int x, int y) {
    for (int v : adjList[x]) {
        if (v == y) return true;
    }
    return false;
}

int main() {
    int n = 5;
    vector<vector<int>> adjList(n);

    // Q1 version listes
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 3, 4);

    // Q2 : affichage des listes d’adjacence
    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (int v : adjList[i]) cout << v << " ";
        cout << endl;
    }

    // Q3 : nombre d’arêtes
    int sumDegrees = 0;
    for (int i = 0; i < n; i++) sumDegrees += (int)adjList[i].size();
    int nbAretes = sumDegrees / 2;
    cout << "NBArretes = " << nbAretes << endl;

    // Q4 : nombre de sommets de degré pair
    int nbDegPair = 0;
    for (int i = 0; i < n; i++) {
        int deg = (int)adjList[i].size();
        if (deg % 2 == 0) nbDegPair++;
    }
    cout << "NBSommetDegreePair = " << nbDegPair << endl;

    // Q5 : test adjacence
    cout << is_adj_list(adjList, 0, 1) << endl; // vrai -> 1
    cout << is_adj_list(adjList, 0, 2) << endl; // faux -> 0

    // Q6 : sommet de degré maximal + son degré
    int bestSommet = 0;
    int maxDeg = (int)adjList[0].size();
    for (int i = 1; i < n; i++) {
        int deg = (int)adjList[i].size();
        if (deg > maxDeg) {
            maxDeg = deg;
            bestSommet = i;
        }
    }
    cout << "Sommet deg max = " << bestSommet << ", deg = " << maxDeg << endl;

    // Q7 : degré moyen
    float degMoy = (float)sumDegrees / (float)n;
    cout << "Degre moyen = " << degMoy << endl;

    return 0;
}

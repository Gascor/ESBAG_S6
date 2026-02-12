#include <iostream>
#include <vector>
using namespace std;

bool is_adj(vector<vector<int>> adj, int x, int y){
    return (adj[x][y] && adj[y][x]);
}

int main(){

    // Question 1 : Initialisation du Graphe
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    adj[0][1] = 1;
    adj[1][0] = 1;
    adj[0][3] = 1;
    adj[3][0] = 1;
    adj[1][2] = 1;
    adj[2][1] = 1;
    adj[1][4] = 1;
    adj[4][1] = 1;
    adj[3][1] = 1;
    adj[1][3] = 1;
    adj[3][4] = 1;
    adj[4][3] = 1;
    // Question 2 : Affichage de la matrice d'adj du graphe
    for (int i = 0; i < (int)adj.size(); i++){
        for (int j = 0; j < (int)adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    // Question 3 : Affichage du nombre d'arretes.
    int NBArretes = 0;
    for (int i = 0; i < (int)adj.size(); i ++){
        for (int j = i; j < (int)adj[i].size(); j++){
            if (adj[i][j] == 1){
                NBArretes++;
            }
        }
    }
    cout << NBArretes << endl;
    // Question 4
    int NBSommetDegreePair = 0;
    for (int i = 0; i < (int)adj.size(); i++){
        int nbvoisin = 0;
        for (int j = 0; j < (int)adj[i].size(); j++){
            if (adj[i][j] == 1){
                nbvoisin++;
                
            }
        }
        if ((nbvoisin % 2) == 0){
            NBSommetDegreePair++;
        }
    }
    cout << NBSommetDegreePair << endl;
    // Question 5 : point x et y sont ils adjancent? on prend dans notre test le 1 et 2 soit x = 0 et y = 1
    cout << is_adj(adj, 0, 1) << endl; // Censé être vrais "1"
    cout << is_adj(adj, 0, 2) << endl; // Censé être faux "0"
    // Question 6 : Degré max et affichage
    int MaxDegree = 0;
    for (int i = 0; i < (int)adj.size(); i++){
        int MaxDegreeTemp = 0;
        for (int j = 0; j < (int)adj[i].size(); j++){
            if (adj[i][j] == 1){
                MaxDegreeTemp++;
            }
        }
        if (MaxDegreeTemp >= MaxDegree){
            MaxDegree = MaxDegreeTemp;
        }
    }
    cout << MaxDegree << endl;
    // Question 7 : Degré Moyen et affichage
    float Degree = 0;
    for (int i = 0; i < (int)adj.size(); i++){
        for (int j = 0; j < (int)adj[i].size(); j++){
            if (adj[i][j] == 1){
                Degree++;
            }
        }
    }
    cout << Degree/adj.size();
    // Question 8 :
    return 0;
}


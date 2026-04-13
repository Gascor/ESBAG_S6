#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// DFS de base: on marque puis on visite les voisin non vu.
void parcours_profondeur(const vector<vector<int>>& graphe, int sommet, vector<bool>& marque) {
    marque[sommet] = true;

    for (size_t voisin = 0; voisin < graphe[sommet].size(); ++voisin) {
        if (graphe[sommet][voisin] == 1 && !marque[voisin]) {
            parcours_profondeur(graphe, static_cast<int>(voisin), marque);
        }
    }
}

// Version qui affiche direct l'ordre de passage.
void parcours_profondeur_affichage_rec(const vector<vector<int>>& graphe, int sommet, vector<bool>& marque) {
    marque[sommet] = true;
    cout << sommet << " ";

    for (size_t voisin = 0; voisin < graphe[sommet].size(); ++voisin) {
        if (graphe[sommet][voisin] == 1 && !marque[voisin]) {
            parcours_profondeur_affichage_rec(graphe, static_cast<int>(voisin), marque);
        }
    }
}

// Petit wrapper: gere aussi les composantes pas conectées.
void parcours_profondeur_affichage(const vector<vector<int>>& graphe) {
    vector<bool> marque(graphe.size(), false);

    for (size_t sommet = 0; sommet < graphe.size(); ++sommet) {
        if (!marque[sommet]) {
            parcours_profondeur_affichage_rec(graphe, static_cast<int>(sommet), marque);
        }
    }
    cout << endl;
}

// Affiche les aretes de l'arbre DFS (u -> v quand v est decouvert pr la 1ere fois).
void parcours_arbre_affichage_rec(const vector<vector<int>>& graphe, int sommet, vector<bool>& marque) {
    marque[sommet] = true;

    for (size_t voisin = 0; voisin < graphe[sommet].size(); ++voisin) {
        if (graphe[sommet][voisin] == 1 && !marque[voisin]) {
            cout << sommet << " -> " << voisin << endl;
            parcours_arbre_affichage_rec(graphe, static_cast<int>(voisin), marque);
        }
    }
}

void parcours_arbre_affichage(const vector<vector<int>>& graphe) {
    vector<bool> marque(graphe.size(), false);

    for (size_t sommet = 0; sommet < graphe.size(); ++sommet) {
        if (!marque[sommet]) {
            parcours_arbre_affichage_rec(graphe, static_cast<int>(sommet), marque);
        }
    }
}

// BFS de base avec une file FIFO (queue)
void parcours_largeur(const vector<vector<int>>& graphe, int sommet, vector<bool>& marque) {
    queue<int> file;
    marque[sommet] = true;
    file.push(sommet);

    while (!file.empty()) {
        int courant = file.front();
        file.pop();

        for (size_t voisin = 0; voisin < graphe[courant].size(); ++voisin) {
            if (graphe[courant][voisin] == 1 && !marque[voisin]) {
                marque[voisin] = true;
                file.push(static_cast<int>(voisin));
            }
        }
    }
}

// Q4 version largeur: affiche l'ordre de visite.
void parcours_largeur_affichage(const vector<vector<int>>& graphe) {
    vector<bool> marque(graphe.size(), false);
    queue<int> file;

    for (size_t sommet = 0; sommet < graphe.size(); ++sommet) {
        if (marque[sommet]) continue;

        marque[sommet] = true;
        file.push(static_cast<int>(sommet));

        while (!file.empty()) {
            int courant = file.front();
            file.pop();
            cout << courant << " ";

            for (size_t voisin = 0; voisin < graphe[courant].size(); ++voisin) {
                if (graphe[courant][voisin] == 1 && !marque[voisin]) {
                    marque[voisin] = true;
                    file.push(static_cast<int>(voisin));
                }
            }
        }
    }

    cout << endl;
}

// Q5 version largeur: aretes de l'arbre BFS.
void parcours_arbre_largeur_affichage(const vector<vector<int>>& graphe) {
    vector<bool> marque(graphe.size(), false);
    queue<int> file;

    for (size_t sommet = 0; sommet < graphe.size(); ++sommet) {
        if (marque[sommet]) continue;

        marque[sommet] = true;
        file.push(static_cast<int>(sommet));

        while (!file.empty()) {
            int courant = file.front();
            file.pop();

            for (size_t voisin = 0; voisin < graphe[courant].size(); ++voisin) {
                if (graphe[courant][voisin] == 1 && !marque[voisin]) {
                    marque[voisin] = true;
                    cout << courant << " -> " << voisin << endl;
                    file.push(static_cast<int>(voisin));
                }
            }
        }
    }
}

int main (){
    printf("Question 1\n");
    printf("Graphe representee sur un vector de vector<int> avec 1 vers 2, 1 vers 5, 1 vers 7, 3 vers 4, 5 vers 2, 5 vers 3, 5 vers 4, 5 vers 7\n");
    int n = 7;
    // Matrice d'adj 7x7 init a 0 (plus simple pr l'exo)
    vector<vector<int>> mat_adj(n, vector<int>(n, 0));
    mat_adj[0][1] = 1;
    mat_adj[0][4] = 1;
    mat_adj[0][6] = 1;
    mat_adj[2][3] = 1;
    mat_adj[4][1] = 1;
    mat_adj[4][2] = 1;
    mat_adj[4][3] = 1;
    mat_adj[4][6] = 1;
    printf("Question 2\n");
    // Affichage "tableau" en ASCII, c'est + stable sous Windows.
    cout << "+";
    for (size_t k = 0; k < mat_adj[0].size(); ++k) cout << "-+";
    cout << endl;
    for(int i = 0; i<=6;i++){
        cout << "|";
        for(int j = 0; j<=6;j++){
            cout << mat_adj[i][j];
            cout << "|";
        }
        cout << endl;
    }
    cout << "+";
    for (size_t k = 0; k < mat_adj[0].size(); ++k) cout << "-+";
    cout << endl;
    printf("Question 3\n");

    vector<bool> marque(n, false);
    int sommet_depart = 0;
    // On lance le parcours depuis le sommet 0 pr verifier vite fait.
    parcours_profondeur(mat_adj, sommet_depart, marque);

    cout << "Marquage apres DFS depuis " << sommet_depart << " : ";
    for (int i = 0; i < n; ++i) {
        cout << marque[i] << " ";
    }
    cout << endl;

    printf("Question 4\n");
    // Ici on affiche l'ordre complet des sommets visites.
    cout << "Sommets visites par DFS : ";
    parcours_profondeur_affichage(mat_adj);
    
    printf("Question 5\n");
    cout << "Aretes de l'arbre de parcours (DFS):" << endl;
    parcours_arbre_affichage(mat_adj);

    printf("Question 6\n");
    vector<bool> marque_largeur(n, false);
    int sommet_depart_largeur = 0;
    parcours_largeur(mat_adj, sommet_depart_largeur, marque_largeur);

    cout << "Marquage apres BFS depuis " << sommet_depart_largeur << " : ";
    for (int i = 0; i < n; ++i) {
        cout << marque_largeur[i] << " ";
    }
    cout << endl;

    cout << "Sommets visites par BFS : ";
    parcours_largeur_affichage(mat_adj);

    cout << "Aretes de l'arbre de parcours (BFS):" << endl;
    parcours_arbre_largeur_affichage(mat_adj);
    
    return 0;
}
#include "geodesico.h"
using namespace std;

#define range pair<int, int>


Grafo::Grafo(int v){
    listaAdy.resize(v);
    vertices = v;
}

void Grafo::agArista(int v, int w){

    listaAdy[v].push_back(w);
    listaAdy[w].push_back(v);
}

bool Grafo::bfsMod(int s) {

    tuple<bool, int, int> tuplita = make_tuple(false, -1, -1);
    
    if (visitados.size() == 0) {
        
        for (int i = 0; i < vertices; i++) {
            visitados.push_back(tuplita);
        }
    }
    else {
        for (int i = 0; i < vertices; i++) {
            visitados[i] = tuplita;
        }
    }

    list<int> queue;

    get<0>(visitados[s]) = true;
    get<1>(visitados[s]) = s;
    get<2>(visitados[s]) = 0;

    queue.push_back(s);
    int parent = s;
    int lvldesc = 0;
    bool esGeodesico = true;

    while (!queue.empty()) {
        s = queue.front();
        parent = s;
       
        queue.pop_front();

        for (auto adyacente : listaAdy[s]) {
            if (!get<0>(visitados[adyacente])) {
                get<0>(visitados[adyacente]) = true;
                get<1>(visitados[adyacente]) = parent;
                get<2>(visitados[adyacente]) = get<2>(visitados[parent]) + 1;
                queue.push_back(adyacente);
            }
            else {
                if (get<2>(visitados[adyacente]) == get<2>(visitados[parent]) + 1){
                    reconstruccionCamino(adyacente, parent, visitados);
                    return false;
                }
            }
        }
    }
    return true;

}

void Grafo::reconstruccionCamino(int ady, int parent, vector<tuple<bool, int, int>> visitados) {

    vector<int> caminoUno;
    vector<int> caminoDos;

    int nodo1;
    int nodo2;

    caminoUno.push_back(ady);
    caminoDos.push_back(ady);

    nodo1 = get<1>(visitados[ady]);
    nodo2 = parent;

    while (nodo1 != nodo2) {

        caminoUno.push_back(nodo1);
        caminoDos.push_back(nodo2);

        nodo1 = get<1>(visitados[nodo1]);
        nodo2 = get<1>(visitados[nodo2]);
    }
    caminoUno.push_back(nodo1);
    caminoDos.push_back(nodo2);

    cout << "0" << endl;
    for (int i = caminoUno.size() - 1; i >= 0;  i--) {
        cout << caminoUno[i] << " ";
    }
    cout << endl;
    for (int i = caminoDos.size() - 1; i >= 0; i--) {
        cout << caminoDos[i] << " ";
    }
    cout << endl;
}

void Grafo::esGeodesico(){

    vector<vector<int>> resTrue;
    vector<int> interno;
    interno.resize(vertices);
    
    bool estado = true;
    for (int i = 0; i < vertices; i++) {
        estado = bfsMod(i);
        if (!estado) {
            break;
        }
        else {
            for (int j = 0; j < visitados.size(); j++) {
                interno[j] = (get<1>(visitados[j]));
            }
            resTrue.push_back(interno);
        }
    }
    if (estado) {
        cout << "1" << endl;
        for (int i = 0; i < resTrue.size(); i++) {
            for (int j = 0; j < resTrue[i].size(); j++) {
                cout << resTrue[i][j] << " ";
            }
            cout << endl;
        }
    }
}
void print(std::vector<int> const& input){

    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}


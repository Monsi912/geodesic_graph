#pragma once
#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

class Grafo {
public:

    int vertices;
    vector<list<int>> listaAdy;

    Grafo(int v);
    void agArista(int v, int w);
    bool bfsMod(int s);
    void reconstruccionCamino(int, int, vector<tuple<bool, int, int>>);
    void esGeodesico();

private:
    vector<tuple<bool, int, int>> visitados;

};
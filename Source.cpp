#include "geodesico.h"

#define range pair<int, int>


void parsearDatos(vector<range>& data) {

    vector<int> rawdata;

    string s;
    cin >> s;

    while (s != "") {
        rawdata.push_back(stoi(s));
        s = "";
        cin >> s;
    }
    for (int i = 0; i < rawdata.size() - 1; i += 2) {
        data.push_back({ rawdata[i], rawdata[i + 1] });
    }
}

int main() {

    vector<range> data;
    parsearDatos(data);
    Grafo g(data[0].first);
    for (int i = 1; i < data.size(); i++)
    {
        g.agArista(data[i].first, data[i].second);
    }

    g.esGeodesico();

    return 0;
}
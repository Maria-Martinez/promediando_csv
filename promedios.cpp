#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;
double promedios_individuales(const char* archivocvv)
{
    ifstream data(archivocvv);
    string line;
    vector<vector<string>> parsedCsv;
    int rowcount=0;
    int colcount=0;
    while (getline(data,line))
    {
        stringstream lineStream(line);
        string cell;
        vector<string> Row;
        colcount=0;
        while (getline(lineStream,cell,','))
        {
            Row.push_back(cell);
            colcount++;

        }
        rowcount++;
        parsedCsv.push_back(Row);

    }
    float sumatoria=0;

    for(int y=2; y<colcount;y++){
        for(int x=0; x<rowcount;x++ ){
        float suma=std::stof(parsedCsv[x][y]);
        sumatoria=(suma+sumatoria);
        }
        sumatoria=sumatoria/rowcount;
        cout << sumatoria;
        sumatoria=0;
        cout <<'\n';

    }
}
int main()
{
    cout << "El promedio de la nota de 5 estudiantes es: "<<'\n';
    promedios_individuales("Promedio5Estud.csv");
    cout << "El promedio de la nota de 10 estudiantes es: "<<'\n';
    promedios_individuales("Promedio10Estud.csv");
    cout << "El promedio de la nota de 15 estudiantes es: "<<'\n';
    promedios_individuales("Promedio15Estud.csv");
    cout << "El promedio de la nota de 20 estudiantes es: "<<'\n';
    promedios_individuales("Promedio20Estud.csv");
    return 0;
}
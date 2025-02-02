#include <iostream>
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Pentagono.h"
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    vector<Geometrica *> vFig;
    Geometrica *pG = nullptr;
    /*
    creo un vector de punteros para guardar puntero de objetos que se vayan creando
    uso un puntero de Geometrica para entender el codigo
    */

    if (argc != 2)
    {
        cout << "El programa se usa así:" << endl;
        cout << "fig_geometricas_file path_to_file" << endl;
        cout << "Se debe indicar la ruta al archivo a leer" << endl;
        return 1;
    }

    string path;
    path = argv[1];
    ifstream archivo;
    archivo.open(path);

    cout << "Se abrirá el archivo: " << path << endl;

    int tipo = 0;
    size_t posicion = 0;
    if (archivo.is_open())
    {
        // Aquí va el codigo que se va a hacer para leer el archivo

        while (getline(archivo, path))
        {
            // en el path tengo el texto que se extrae de datos.txt
            posicion = path.find(" ", posicion);
            // cout << path << "-> " << posicion <<endl;
            tipo = atoi(path.substr(0, posicion).c_str());
            switch (tipo)
            {
            case circulo:
                pG = new Circulo(path.substr(posicion + 1));
                break;
            case cuadrado:
                pG = new Cuadrado(path.substr(posicion + 1));
                break;
            case triangulo:
                pG = new Triangulo(path.substr(posicion + 1));
                break;
            case pentagono:
                pG = new Pentagono(path.substr(posicion + 1));
                break;
            default:
                break;
            }
<<<<<<< HEAD
            vFig.push_back(pG);
=======
       	vFig.push_back( pG );

>>>>>>> refs/remotes/origin/main
        }
        cout << vFig.size() << endl;
        archivo.close();
        /*
        ese puntero lo agrega a la lista geometrica
        */
    }

    // Procesar el vector
    for (int i = 0; i < vFig.size(); ++i)
    {
        /*
        -> miembro de un puntero, le indico que llame a la funcion area a donde apunta el puntero
        *() desreferencia el puntero, le indico que llame a la funcion area del objeto al que apunta el puntero

        */
        cout << "El área es: " << vFig[i]->area() << endl;
        cout << *(vFig[i]) << endl;
        cout << vFig[i]->getTipo() << endl;
        if (vFig[i]->getTipo() == fig_G::circulo)
        {
            Circulo *ptr = (Circulo *)vFig[i];
            cout << *ptr << endl;
        }
        cout << vFig[i]->queSoy() << endl
             << endl;
    }

    // NO olvidar destruir la memoria dinámica creada

    for (int i = 0; i < vFig.size(); ++i)
    {
        delete vFig[i];
    }
    return 0;
}

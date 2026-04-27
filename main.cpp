#include <iostream>
#include "Product.h"

using namespace std;

int main()
{
    Product miProducto;

    // Probamos la entrada de datos
    cin >> miProducto;

    // Probamos la salida con el formato que creamos
    cout << "\nDatos del producto guardado:" << endl;
    cout << miProducto << endl;

    return 0;
}
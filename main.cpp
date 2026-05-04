#include <iostream>
#include "Product.h"

using namespace std;

int main()
{
    // 1. Producto automatico
    Product p1;
    cout << "--- Prueba 1: Producto por defecto ---" << endl;
    cout << p1 << endl
         << endl;

    // 2. Producto con parametros
    Product p2("Ceviche", 10, 35.50);
    cout << "--- Prueba 2: Producto con parametros ---" << endl;
    cout << p2 << endl
         << endl;

    // 3. Prueba de entrada por teclado (operator >>)
    Product p3;
    cout << "--- Prueba 3: Entrada manual ---" << endl;
    cin >> p3;

    cout << "\nDatos del producto registrado:" << endl;
    cout << p3 << endl;

    // 4. Prueba lógica simple (Operadores de comparación)
    cout << "\n--- Prueba 4: Comparacion de codigos ---" << endl;
    if (p2 > p1)
    {
        cout << "El codigo de " << p2.getName() << " es mayor que el de " << p1.getName() << endl;
    }
    cout <<"Presione Enter para salir . . .";
    system("pause");

    return 0;
}
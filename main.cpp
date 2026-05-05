#include <iostream>
#include <limits>
#include "Product.h"
#include "Store.h"

using namespace std;

// Función auxiliar para pausar la pantalla de forma limpia
void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main()
{
    Store warike;
    int opcion;

    do {
        system("cls"); // Limpia la pantalla (en Windows)
        cout << "========================================" << endl;
        cout << "   SISTEMA DE GESTION - EL WARIKE" << endl;
        cout << "========================================" << endl;
        cout << "1. Registrar Compra (Entrada de Almacen)" << endl;
        cout << "2. Ver Inventario Completo" << endl;
        cout << "3. Ver Reporte de Gastos y Ganancias" << endl;
        cout << "0. Salir del Sistema" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        
        if (!(cin >> opcion)) {
            cout << "Error: Por favor ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pausar();
            continue;
        }

        switch (opcion) {
            case 1:
                warike.registerPurchase();
                pausar();
                break;

            case 2:
                warike.showStore();
                pausar();
                break;

            case 3:
                warike.showDailyBalance();
                pausar();
                break;

            case 0:
                cout << "Saliendo del sistema... ¡Buen dia!" << endl;
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                pausar();
                break;
        }

    } while (opcion != 0);
    system("pause");

    return 0;
}
#include <iostream>
#include <limits>
#include "Product.h"
#include "Store.h"
#include "Saucers.h"

using namespace std;

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}

int main()
{
    Store warike;
    int opcion;

    do {
        system("cls"); 
        cout << "========================================" << endl;
        cout << "   SISTEMA DE GESTION - EL WARIKE" << endl;
        cout << "========================================" << endl;
        cout << "1. Registrar Compra" << endl;
        cout << "2. Ver Inventario Completo del Almace" << endl;
        cout << "3. Registrar Nuevo Platillo en la Carta" << endl;
        cout << "4. Ver Carta de Platillos" << endl;
        cout << "5. Registrar Venta (Descontar de Almacen)" << endl;
        cout << "6. Ver Reporte de Gastos y Ganancias" << endl;
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
        cin.ignore(1000, '\n'); // Limpiar búfer inmediatamente tras leer la opción

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
                warike.registerSaucer();
                pausar();
                break;
            
            case 4:
                warike.showMenu();
                pausar();
                break;

            case 5:
                warike.sellSaucer();
                pausar();
                break;

            case 6:
                warike.showDailyBalance();
                pausar();
                break;

            case 0:
                cout << endl << "Saliendo del sistema..." << endl << endl;
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                pausar();
                break;
        }

    } while (opcion != 0);

    return 0;
}
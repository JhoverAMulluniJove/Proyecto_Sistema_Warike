#include "Product.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Product::contadorID = 1;

// Implementacion de los constructores
Product::Product() : name("(void)"), amount(0.0f), acquisitionCost(0.0f), next(nullptr)
{
    code = contadorID++;
}

Product::Product(string n, float a, float c, Product *q)
    : name(n), amount(a), acquisitionCost(c), next(q)
{
    code = contadorID++;
}

// Destructor
Product::~Product() {}

// Implementacion de Sobrecarga de operadores de flujo
istream &operator>>(istream &is, Product &obj)
{
    cout << "Nombre del Producto: ";
    is >> obj.name;
    cout << "Cantidad en stock: ";
    is >> obj.amount;
    cout << "Precio unitario: ";
    is >> obj.acquisitionCost;
    return is;
}

ostream &operator<<(ostream &os, const Product &obj)
{
    os << "ID: " << setw(5) << setfill('0') << obj.code
       << " | " << setw(12) << setfill(' ') << obj.name
       << " | Cant: " << obj.amount
       << " | Costo Unit: S/." << fixed << setprecision(2) << obj.acquisitionCost;
    return os;
}
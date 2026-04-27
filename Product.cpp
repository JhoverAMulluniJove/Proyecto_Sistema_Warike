#include "Product.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Implementacion de los constructores
Product::Product() : code(0), name("(void)"), amount(0.0f), price(0.0f), next(nullptr) {}

Product::Product(int c, string n, float a, float p, Product *q)
    : code(c), name(n), amount(a), price(p), next(q) {}

// Destructor
Product::~Product() {}

// Implementacion de Sobrecarga de operadores de flujo
istream &operator>>(istream &is, Product &obj)
{
    cout << "Nombre del Producto: ";
    is >> obj.name;
    cout << "Codigo(ID): ";
    is >> obj.code;
    cout << "Cantidad en stock";
    is >> obj.amount;
    cout << "Precio unitario: ";
    is >> obj.price;
    return is;
}

ostream &operator<<(ostream &os, const Product &obj)
{
    os << "ID: " << setw(5) << setfill('0') << obj.code
       << " | " << setw(12) << setfill(' ') << obj.name
       << " | Cant: " << obj.amount
       << " | Precio: S/." << fixed << setprecision(2) << obj.price;
    return os;
}
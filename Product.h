#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ProductPointer;

class Product
{
private:
    // Caracteristicas basicas
    int code;
    string name;
    float amount;
    float price;

    // Enlace a otros archivos
    Product *next;

public:
    // Constructor: Inicializa las caracteristicas
    Product() : code(0), name("(void)"), amount(0.0f), price(0.0f), next(nullptr) {}

    Product(int c, string n, float a, float p, Product *q = nullptr) : code(c), name(n), amount(a), price(p), next(q) {}

    // Destructor simple
    ~Product() {}

    // Getters y Setters (Acceso a caracteristicas)
    int getCode() const { return code; }
    string getName() const { return name; }
    float getAmount() const { return amount; }
    float getPrice() const { return price; }

    void setCode(int c) { code = c; }
    void setName(string n) { name = n; }
    void setAmount(float a) { amount = a; }
    void setPrice(float p) { price = p; }

    // Acceso al enlace para el archivo de logica
    Product *getNext() const { return next; }
    void setNext(Product *n) { next = n; }

    // Reglas de comparacion
    bool operator<(const Product &other) const { return code < other.code; }
    bool operator>(const Product &other) const { return code > other.code; }
    bool operator==(const Product &other) const { return code == other.code; }
    bool operator!=(const Product &other) const { return !(*this == other); }

    // Entrada y Salida de Datos
    friend istream &operator>>(istream &is, Product &obj);
    friend ostream &operator<<(ostream &os, const Product &objt);
};

// Implementacion de Entrada/Salida
istream &operator>>(istream &is, Product &obj)
{
    cout << "Nombre del producto: ";
    is >> obj.name;
    cout << "Codigo (ID): ";
    is >> obj.code;
    cout << "Cantidad en stock: ";
    is >> obj.amount;
    return is;
}
ostream &operator<<(ostream &os, const Product &obj)
{
    os << "ID: " << setw(5) << setfill('0') << obj.code
       << " | " << setw(15) << setfill(' ') << obj.name
       << " | Cant: " << fixed << setprecision(2) << obj.amount;
    return os;
}
#endif
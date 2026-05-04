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
    static int contadorID;
    int code;
    string name;
    float amount;
    float price;

    // Enlace a otros archivos
    Product *next;

public:
    // Constructor: Inicializa las caracteristicas
    Product();
    Product(string n, float a, float p, Product *q = nullptr);
    // Destructor simple
    ~Product();

    // Getters
    int getCode() const { return code; }
    string getName() const { return name; }
    float getAmount() const { return amount; }
    float getPrice() const { return price; }

    // Setters
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
#endif
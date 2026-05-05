#include "Store.h"
#include <iostream>

using namespace std;

Store::Store() : head(nullptr), totalExpenes(0.0f), totalRevenue(0.0f){}

Store::~Store() {
    Product* current = head;
    while (current != nullptr) {
        Product* next = current->getNext();
        delete current;
        current = next;
    }
}

Product* Store::findProductByName(string name){
    Product* temp = head;
    
    while (temp != nullptr)
    {
        if (temp->getName() == name) return temp;
        temp = temp->getNext();
    }
    return nullptr;
}

Product* Store::findProductByID(int id){
    Product* temp = head;
    while (temp != nullptr)
    {
        if (temp->getCode() == id) return temp;
        temp = temp->getNext();
    }
    return nullptr;
}

void Store::registerPurchase(){
    string name;
    float quantity, cost;

    cout << "\n--- REGISTRO DE COMPRA ---" << endl;
    cout <<"Nombre del Producto: "; cin >> name;
    cout <<"Cantidad comprada: "; cin >> quantity;
    cout <<"Costo unitario de compra: "; cin >> cost;

    //Calculo del gasto
    totalExpenes += (quantity * cost);

    Product* existing = findProductByName(name);

    if(existing != nullptr){
        existing->setAmount(existing->getAmount() + quantity);
        cout << "Stock actualizado. Nuevo stock de " << name << ": " << existing->getAmount() << endl;
    } else{

        Product* newProduct = new Product(name, quantity, cost);

        newProduct->setNext(head);
        head = newProduct;

        cout << "Nuevo producto registrado en el almacen con ID: " << newProduct->getCode() << endl;
    }
}

void Store::showStore() const{
    cout <<"\n--- INVENTARIO ACTUAL ---"<<endl;
    Product* temp = head;
    if(temp == nullptr){
        cout << "El almacen esta vacio. "<<endl;
        return;
    }
    while (temp != nullptr){
        cout << *temp << endl;
        temp = temp->getNext();
    }
    cout << "----------------------------------" << endl;
}

void Store::showDailyBalance() const{
    cout << "\n==================================" << endl;
    cout << "      REPORTE FINANCIERO" << endl;
    cout << "==================================" << endl;
    cout << "Total Gastado en Compras: S/." << fixed << setprecision(2) << totalExpenes << endl;
    cout << "Total Ganado en Ventas:   S/." << totalRevenue << endl;
    cout << "Utilidad Neta:            S/." << (totalRevenue - totalExpenes) << endl;
    cout << "==================================" << endl;
}
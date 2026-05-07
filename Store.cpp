#include "Store.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Store::Store() : head(nullptr), totalExpenes(0.0f), totalRevenue(0.0f){
    loadFromFile(); 
}

Store::~Store() {
    Product* current = head;
    while (current != nullptr) {
        Product* next = current->getNext();
        delete current;
        current = next;
    }
}

void Store::saveToFile() const {
    ofstream archivo("almacen.txt");
    if(!archivo.is_open()) return;

    Product* temp = head;
    while(temp != nullptr){
        //Guardamos los datos separados
        archivo << temp->getName() << "|" 
                << temp->getAmount() << "|" 
                << temp->getPrice() << endl;
        temp = temp->getNext();
    }
    archivo.close();
}

void Store::loadFromFile(){
    ifstream archivo("almacen.txt");
    if(!archivo.is_open())return;

    string linea;
    while (getline(archivo, linea)){
        if(linea.empty()) continue;

        stringstream ss(linea);
        string name, s_quantity, s_price;

        if(getline(ss,name,'|') && getline(ss,s_quantity, '|') && getline(ss, s_price)){
            float quantity = stof(s_quantity);
            float price = stof(s_price);

            Product* newProduct = new Product(name, quantity, price);
            newProduct->setNext(head);
            head = newProduct;
        }
    }
    archivo.close();
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
        cout << endl << "Stock actualizado. Nuevo stock de " << name << ": " << existing->getAmount() << endl;
    } else{

        Product* newProduct = new Product(name, quantity, cost);

        newProduct->setNext(head);
        head = newProduct;

        cout << endl << "Nuevo producto registrado en el almacen con ID: " << newProduct->getCode() << endl;
    }
    saveToFile();
    cout<< endl<<"Datos guardados en almacent.txt"<<endl;
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
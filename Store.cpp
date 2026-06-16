//Almacen

#include "Store.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

string aMinusculas(string cadena) {
    transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
    return cadena;
}

Store::Store() : head(nullptr), totalExpenses(0.0f), totalRevenue(0.0f){
    loadFromFile(); 
    loadMenuFromFile();
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
        archivo << aMinusculas(temp->getName()) << "|" 
                << temp->getAmount() << "|" 
                << temp->getAcquisitionCost() << endl;
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

            if(findProductByName(name) == nullptr){
                Product* newProduct = new Product(name, quantity, price);
                newProduct->setNext(head);
                head = newProduct;
            } 
        }
    }
    archivo.close();
}

void Store::saveMenuToFile() const{
    ofstream archivo("carta.txt");
    if(!archivo.is_open()) return;

    for(const auto& saucer : menu){
        archivo << aMinusculas(saucer.getName()) << "|" << saucer.getSalePrice() << "|";
        for(const auto& ing : saucer.getRecipe()){
            archivo << aMinusculas(ing.name) << ":" << ing.quantityNeeded << ";";
        }
        archivo << endl;
    }
    archivo.close();
}

void Store::loadMenuFromFile() {
    ifstream archivo("carta.txt");
    if(!archivo.is_open()) return;

    string linea;
    while(getline(archivo, linea)) {
        if(linea.empty()) continue;

        stringstream ss(linea);
        string saucerName, s_price, s_recipe;

        if(getline(ss, saucerName, '|') && getline(ss, s_price, '|') && getline(ss, s_recipe)) {
            float price = stof(s_price);
            Saucer loadedSaucer(saucerName, price);

            stringstream ss_recipe(s_recipe);
            string ingredienteIndividual;
            
            while(getline(ss_recipe, ingredienteIndividual, ';')) {
                if(ingredienteIndividual.empty()) continue;
                stringstream ss_ing(ingredienteIndividual);
                string ingName, s_qty;
                if(getline(ss_ing, ingName, ':') && getline(ss_ing, s_qty)) {
                    loadedSaucer.addIngredient(ingName, stof(s_qty));
                }
            }
            menu.push_back(loadedSaucer);
        }
    }
    archivo.close();
}

Product* Store::findProductByName(string name){
    Product* temp = head;
    
    string nameMin = aMinusculas(name);
    while (temp != nullptr)
    {
        if (aMinusculas(temp->getName()) == nameMin) return temp;
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
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void Store::registerPurchase(){
    string name;
    float quantity, cost;

    cout << "\n--- REGISTRO DE COMPRA ---" << endl;
    cout <<"Nombre del Producto: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, name);

    cout <<"Cantidad comprada: "; cin >> quantity;
    cout <<"Costo unitario de compra: "; cin >> cost;
    cin.ignore(1000, '\n');

    //Calculo del gasto
    totalExpenses += (quantity * cost);

    Product* existing = findProductByName(name);

    if(existing != nullptr){
        existing->setAmount(existing->getAmount() + quantity);
        existing->setAcquisitionCost(cost);
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
    cout << "Total Gastado en Compras: S/." << fixed << setprecision(2) << totalExpenses << endl;
    cout << "Total Ganado en Ventas:   S/." << totalRevenue << endl;
    cout << "Utilidad Neta:            S/." << (totalRevenue - totalExpenses) << endl;
    cout << "==================================" << endl;
}

Saucer* Store::findSaucerByName(string name) {
    string nameMin = aMinusculas(name);
    for (size_t i = 0; i < menu.size(); i++) {
        if (aMinusculas(menu[i].getName()) == nameMin) {
            return &menu[i];
        }
    }
    return nullptr;
}

void Store::registerSaucer() {
    string saucerName;
    float price;

    cout << "\n--- REGISTRO DE NUEVO PLATILLO EN LA CARTA ---" << endl;
    cout << "Nombre del Platillo: "; 
    if (cin.peek() == '\n') cin.ignore(); 
    getline(cin, saucerName); 

    if (findSaucerByName(saucerName) != nullptr) {
        cout << "El platillo '" << saucerName << "' ya existe en la carta." << endl;
        return;
    }

    cout << "Precio de venta al publico: S/."; cin >> price;
    cin.ignore(1000, '\n');

    Saucer newSaucer(saucerName, price);

    char continuar;
    do {
        string ingName;
        float qty;

        cout << "\n-> Ingrediente para la receta: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, ingName);
        
        if (findProductByName(ingName) == nullptr) {
            cout << "[Aviso] El insumo '" << ingName << "' no existe en el almacen actualmente." << endl;
        }

        cout << "-> Cantidad necesaria (en kg/unidades): "; cin >> qty;
        cin.ignore(1000, '\n');
        
        newSaucer.addIngredient(ingName, qty);

        cout << "Deseas añadir otro ingrediente a este plato? (s/n): "; cin >> continuar;
        cin.ignore(1000, '\n');
    } while (continuar == 's' || continuar == 'S');

    menu.push_back(newSaucer);
    cout << "\nPlatillo '" << saucerName << "' registrado con exito en la carta!" << endl;
}

void Store::showMenu() const {
    cout << "\n========================================" << endl;
    cout << "          CARTA DE EL WARIKE" << endl;
    cout << "========================================" << endl;
    if (menu.empty()) {
        cout << "La carta esta vacia. Registra un plato primero." << endl;
        return;
    }
    for (const auto& saucer : menu) {
        saucer.showSaucer(); 
        cout << "----------------------------------------" << endl;
    }
}

void Store::sellSaucer(){
    if(menu.empty()){
        cout<<"\nNo hay platillos en la carta. Registre . . ." << endl;
        return;
    }

    string targetName;
    cout<<"\n---Registrar VENTA ---"<<endl;
    cout<<"Nombre del platillo a vender: ";
    if(cin.peek() == '\n') cin.ignore();
    getline(cin,targetName);

    Saucer* chosenSaucer = findSaucerByName(targetName);
    if (chosenSaucer == nullptr) {
        cout << "El platillo '" << targetName << "' no existe en la carta." << endl;
        return;
    }

    // Paso 1: Simulación y Verificación de Stock de TODOS los ingredientes
    const auto& recipe = chosenSaucer->getRecipe();
    for (const auto& ingredient : recipe) {
        Product* storageItem = findProductByName(ingredient.name);
        
        if (storageItem == nullptr) {
            cout << "\n[VENTA CANCELADA] Falta el insumo fundamental: " << ingredient.name << endl;
            return;
        }
        
        if (storageItem->getAmount() < ingredient.quantityNeeded) {
            cout << "\n[STOCK INSUFICIENTE] No se puede preparar " << chosenSaucer->getName() << endl;
            cout << "Falta: " << storageItem->getName() << " (Tiene: " << storageItem->getAmount() 
                 << " | Requiere: " << ingredient.quantityNeeded << ")" << endl;
            return;
        }
    }

    // Paso 2: Descontar de forma real si pasó la verificación completa
    for (const auto& ingredient : recipe) {
        Product* storageItem = findProductByName(ingredient.name);
        storageItem->setAmount(storageItem->getAmount() - ingredient.quantityNeeded);
    }

    totalRevenue += chosenSaucer->getSalePrice();
    saveToFile(); // Actualizar almacén en el disco plano
    
    cout << "\n¡Venta procesada con éxito!" << endl;
    cout << "Se descontaron los insumos correspondientes de la cocina." << endl;
    cout << "Monto ingresado a caja: S/." << chosenSaucer->getSalePrice() << endl;
}
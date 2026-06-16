#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include "Saucers.h"
#include <vector>
#include <string>

class Store
{
private:
    Product* head;

    float totalExpenses;     //Acumulador de Compras
    float totalRevenue;     //Acumulador de Ventas
    vector<Saucer> menu;

    void saveToFile() const;
    void loadFromFile();
    void saveMenuToFile() const;
    void loadMenuFromFile();
    
public:
    Store();
    ~Store();

    // Gestión del Almacén
    void registerPurchase();
    void showStore() const;
    void showDailyBalance() const;
    Product* findProductByName(string name);
    Product* findProductByID(int id);

    // Gestion de Platillos
    void registerSaucer();
    void showMenu() const;
    Saucer* findSaucerByName(string name);
    void sellSaucer();
};

#endif
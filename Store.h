#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include <vector>
#include <string>

class Store
{
private:
    Product* head;
    float totalExpenes;     //Acumulador de Compras
    float totalRevenue;     //Acumulador de Ventas

    void saveToFile() const;
    void loadFromFile();
    
public:
    Store();
    ~Store();

    // Registro de Compra
    void registerPurchase();

    //Visualizacion del Almacen
    void showStore() const;

    //Visualizacion de Balance final del dia
    void showDailyBalance() const;

    //Verifica la existencia de algun Producto en el almacen
    Product* findProductByName(string name);

    //Busca Producto mediante codigo
    Product* findProductByID(int id);
};

#endif
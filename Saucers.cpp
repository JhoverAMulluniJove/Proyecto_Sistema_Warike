#include "Saucers.h"
#include "iostream"

using namespace std;

Saucer::Saucer(string n, float p) : name(n), salePrice(p){}

void Saucer::addIngredient(string ingredientName, float quantity){
    IngredientsRecipe newIngrediente;
    newIngrediente.name = ingredientName;
    newIngrediente.quantityNeeded = quantity;

    recipe.push_back(newIngrediente);
}

void Saucer::showwSaucer()const{
    cout << "Platillo: " << name << " | Precio de Venta: S/." << salePrice << endl;
    cout << "  -> Ingredientes necesarios:" << endl;
    
    if (recipe.empty()) {
        cout << "     (No se han definido ingredientes todavia)" << endl;
    } else {
        for (const auto& ingredient : recipe) {
            cout << "     - " << ingredient.name << ": " << ingredient.quantityNeeded << endl;
        }
    }
}
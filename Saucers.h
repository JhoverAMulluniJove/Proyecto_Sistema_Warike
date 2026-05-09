#ifndef SAUCERS_H
#define SAUCERS_H

#include <string>
#include <vector>

using namespace std;

struct IngredientsRecipe{
    string name;
    float quantityNeeded;
};

class Saucer{
    private:
        string name;
        float salePrice;
        vector<IngredientsRecipe> recipe;

    public:
        Saucer(string n = "", float p = 0.0f);
        void addIngredient(string ingredientName, float quantity);

        string getName() const {return name;}
        float getSalePrice() const {return salePrice;}
        const vector<IngredientsRecipe> & getRecipe() const {return recipe;}

        void showwSaucer()const;
};

#endif
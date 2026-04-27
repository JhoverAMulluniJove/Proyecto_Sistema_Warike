#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
/* - - - - - - - - - - - - - - - - - - */
class ProductPointer;

class Product
{
private:
    int code;
    string name;
    float amount;

    Product *next;

public:
    Product();
    Product(int, string, float, Product *);

    int getCode();
    string getName();
    float getAmount();

    void setCode(int);
    void setName(string);
    void setAmount(float);

    bool operator<(Product &);
    bool operator>(Product &);
    bool operator==(Product &);
    bool operator!=(Product &);

    friend istream &operator>>(istream &, Product &);
    friend ostream &operator<<(ostream &, Product &);

    friend class ProductPointer;
};
/* - - - - - - - - - - - - - - - - - - */
Product ::Product()
{
    name = "(void)";
    code = 0;
    amount = 0;
    next = NULL;
}

Product ::Product(int c, string n, float a, Product *q)
{
    name = n;
    code = c;
    amount = a;
    next = q;
}
/* - - - - - - - - - - - - - - - - - - */
int Product ::getCode()
{
    return (code);
}
string Product ::getName()
{
    return (name);
}
float Product ::getAmount()
{
    return (amount);
}
/* - - - - - - - - - - - - - - - - - - */
void Product ::setCode(int code_)
{
    code = code_;
}
void Product ::setName(string name_)
{
    name = name_;
}
void Product ::setAmount(float amount_)
{
    amount = amount_;
}
/* - - - - - - - - - - - - - - - - - - */
bool Product ::operator>(Product &objA)
{
    if (code > objA.code)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool Product ::operator<(Product &objA)
{
    if (code < objA.code)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool Product ::operator==(Product &objA)
{
    if (code == objA.code)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool Product ::operator!=(Product &objA)
{
    if (code != objA.code)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
istream &operator>>(istream &read, Product &objA)
{
    return read;
}
ostream &operator<<(ostream &write, Product &objA)
{
    write << "Producto: ";
    write << objA.name;
    write << "Codigo: ";
    write << objA.code;
    write << "Cantidad: ";
    write << objA.amount;
    write << "Precio: ";
    write << " S/.";
    return write;
}

class ProductPointer
{
private:
    Product *p;

public:
    ProductPointer();
    ProductPointer(Product *);
};

ProductPointer::ProductPointer()
{
    p = NULL;
}

ProductPointer ::ProductPointer(Product *w)
{
    p = w;
}

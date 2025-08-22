// SRP:- Single responsibility principle.

#include <iostream>
#include <vector>

class Product
{
public:
    std::string name;
    double price;

    Product(std::string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

// shoping cart
class ShoppingCart
{
public:
    std::vector<Product *> products;

    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    const std::vector<Product *> &getProducts()
    {
        return products;
    }

    double calculateTotal()
    {
        int totalPrice = 0;
        for (auto it : products)
        {
            totalPrice += it->price;
        }
        return totalPrice;
    }

    void printInvoice()
    {
        std::cout << "Shopping cart Invoice:\n";
        for (auto it : products)
        {
            std::cout << it->name << " - $" << it->price << std::endl;
        }
        std::cout << "Total price is " << calculateTotal() << std::endl;
    }

    void saveToDb()
    {
        std::cout << "Data saved in DB" << std::endl;
    }
};

int main()
{
    Product *p1 = new Product("mobile", 9999.00);
    Product *p2 = new Product("Laptop", 89000.00);

    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(p1);
    cart->addProduct(p2);
    cart->addProduct(new Product("Bag", 1000));
    // cart->getProducts();
    cart->printInvoice();
    cart->saveToDb();

    return 0;
}
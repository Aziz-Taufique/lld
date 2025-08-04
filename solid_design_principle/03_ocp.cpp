// OCP:- Open close principle.
// A calss should be open for extension but close for modification.

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

class ShopingCart
{
public:
    std::vector<Product *> products;

    void addProducts(Product *p)
    {
        products.push_back(p);
    }

    std::vector<Product *> &getProducts()
    {
        return products;
    }

    double calculateTotalPrice()
    {
        double totalPrice = 0;
        for (auto it : products)
        {
            totalPrice += it->price;
        }
        return totalPrice;
    }
};

class ShopingCartPrinter
{
    ShopingCart *cart;

public:
    ShopingCartPrinter(ShopingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        std::cout << "Shopping cart Invoice" << std::endl;
        for (auto it : cart->getProducts())
        {
            std::cout << it->name << " - $" << it->price << std::endl;
        }
        std::cout << "Total price is " << cart->calculateTotalPrice() << std::endl;
    }
};

// it break OCP
class ShopingCartStorage
{
    ShopingCart *cart;

public:
    ShopingCartStorage(ShopingCart *cart)
    {
        this->cart = cart;
    }

    void saveToMongodb()
    {
        std::cout << "Saved to mongodb database..." << std::endl;
    }

    void saveToSQLdb()
    {
        std::cout << "Saved to SQL database..." << std::endl;
    }

    void saveToFile()
    {
        std::cout << "Saved to File..." << std::endl;
    }
};

int main()
{
    ShopingCart *cart = new ShopingCart();

    cart->addProducts(new Product("mobile", 9999));
    cart->addProducts(new Product("Laptop", 10000));

    ShopingCartPrinter *printer = new ShopingCartPrinter(cart);
    printer->printInvoice();

    ShopingCartStorage *db = new ShopingCartStorage(cart);
    db->saveToFile();
    db->saveToMongodb();
    db->saveToSQLdb();
    std::cout << cart->calculateTotalPrice() << std::endl;
}
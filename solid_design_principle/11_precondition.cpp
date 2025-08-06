#include <iostream>

// A precondition must be satisfied before a method can be executed.
// sub classes can weaken the precondition but cannot strengthen it.
class User
{
public:
    virtual void setPassword(std::string password)
    {
        if (password.length() < 8)
        {
            throw std::invalid_argument("Password must be atleast 8 character long.");
        }
        std::cout << "Password set successfully" << std::endl;
    }
};

class AdminUser : public User
{
public:
    void setPassword(std::string password) override
    {
        if (password.length() < 6)
        {
            throw std::invalid_argument("Password must be atleast 6 character long.");
        }
        std::cout << "Password set successfully" << std::endl;
    }
};

int main()
{
    User *user = new User();
    user->setPassword("asdfadsfa");

    User *adminuser = new AdminUser();
    adminuser->setPassword("sdaddaasd");
    return 0;
}
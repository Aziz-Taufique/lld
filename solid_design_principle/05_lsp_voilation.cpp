#include <iostream>
#include <string>
#include <vector>

class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount()
    {
        this->balance = 0;
    }

    void deposit(double amount) override
    {
        balance += amount;
        std::cout << "Deposited: " << amount << " Current balance is " << balance << std::endl;
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << " From saving account> Current balance is " << balance << std::endl;
        }
        else
        {
            std::cout << "Insufficient balance. Cannot withdrown" << std::endl;
        }
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount()
    {
        this->balance = 0;
    }

    void deposit(double amount) override
    {
        balance += amount;
        std::cout << "Deposited: " << amount << " Current balance is " << balance << std::endl;
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << " From current account> Current balance is " << balance << std::endl;
        }
        else
        {
            std::cout << "Insufficient balance. Cannot withdrown" << std::endl;
        }
    }
};

class FixedDepositAccount : public Account
{
private:
    double balance;

public:
    FixedDepositAccount()
    {
        this->balance = 0;
    }

    void deposit(double amount) override
    {
        balance += amount;
        std::cout << "Deposited: " << amount << " Current balance is " << balance << std::endl;
    }

    void withdraw(double amount) override
    {
        throw std::logic_error("Withdrown not allowed in fixed term acccount");
    }
};

class BankClient
{
    std::vector<Account *> accounts;

public:
    BankClient(std::vector<Account *> accounts)
    {
        this->accounts = accounts;
    }

    void proccessTransections()
    {
        for (Account *it : accounts)
        {
            it->deposit(1000);

            try
            {
                it->withdraw(500);
            }
            catch (const std::logic_error &e)
            {
                std::cout << "Exception: " << e.what() << std::endl;
            }
        }
    }
};

int main()
{
    std::vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedDepositAccount());

    BankClient *client = new BankClient(accounts);

    client->proccessTransections();

    return 0;
}
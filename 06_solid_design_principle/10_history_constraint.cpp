#include <iostream>

// sub class methods should not be allowed state changes what base class never allowed.

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double amount)
    {
        if (amount < 0)
            throw std::invalid_argument("Balance can't be negative");
        balance += amount;
    }

    // History constraint: Withdrawn should be allowed.
    virtual void withdraw(double amount)
    {
        if (balance - amount < 0)
            throw std::runtime_error("Insufficient balance.");
        balance -= amount;
        std::cout << "Amount withdrawn. Remaining balance is " << balance << std::endl;
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    FixedDepositAccount(double amount) : BankAccount(amount) {}

    // LSP break! History constraint broke.
    // Parent class behaviour change : Now withdraw in not allowed.
    // This class will break client code that relies on withraw.
    void withdraw(double amount)
    {
        throw std::runtime_error("Withdrawn not allowed in fixed deposit account");
    }
};

int main()
{

    BankAccount *bankAccount = new BankAccount(1000);
    bankAccount->withdraw(500);

    FixedDepositAccount *fx = new FixedDepositAccount(800);
    fx->withdraw(400);

    return 0;
}
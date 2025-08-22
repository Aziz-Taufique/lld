#include <iostream>
#include <vector>
#include <typeinfo>

class DepositOnlyAcc
{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawAcc : public DepositOnlyAcc
{
public:
    virtual void withdraw(double amount) = 0;
};

/// /////////////////////////////////
class CurrentAccount : public WithdrawAcc
{
private:
    double balance;

public:
    CurrentAccount() : balance(0) {}

    void deposit(double amount) override
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "Deposited " << amount << " , Current balance is " << balance << std::endl;
        }
        else
        {
            std::cout << "Please provide valid amount." << std::endl;
        }
    }

    void withdraw(double amount) override
    {
        if (amount >= balance)
        {
            balance -= amount;
            std::cout << "Widhrawn " << amount << ", from current account. Current balance is " << balance << std::endl;
        }
        else
        {
            std::cout << "Insufficent balance." << std::endl;
        }
    }
};

class SavigAccount : public WithdrawAcc
{
private:
    double balance;

public:
    SavigAccount() : balance(0) {}

    void deposit(double amount) override
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "Deposited " << amount << " , Current balance is " << balance << std::endl;
        }
        else
        {
            std::cout << "Please provide valid amount." << std::endl;
        }
    }

    void withdraw(double amount) override
    {
        if (amount >= balance)
        {
            balance -= amount;
            std::cout << "Widhrawn " << amount << ", from saving account. Current balance is " << balance << std::endl;
        }
        else
        {
            std::cout << "Insufficent balance." << std::endl;
        }
    }
};

class FixedDepositAcc : public DepositOnlyAcc
{
private:
    double balance;

public:
    FixedDepositAcc() : balance(0) {}

    void deposit(double amount) override
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "Deposited " << amount << " , Current balance is " << balance << std::endl;
        }
        else
        {
            std::cout << "Please provide valid balance." << std::endl;
        }
    }
};

class BankClient
{
    std::vector<WithdrawAcc *> withdrawAcc;
    std::vector<DepositOnlyAcc *> depositOnlyAcc;

public:
    BankClient(std::vector<DepositOnlyAcc *> depositOnlyAcc, std::vector<WithdrawAcc *> withdrawAcc)
    {
        this->depositOnlyAcc = depositOnlyAcc;
        this->withdrawAcc = withdrawAcc;
    }

    void processTransection()
    {
        for (auto it : withdrawAcc)
        {
            it->deposit(1000);
            it->withdraw(500);
        }

        for (DepositOnlyAcc *it : depositOnlyAcc)
        {
            it->deposit(1000);
        }
    }
};

int main()
{
    std::vector<WithdrawAcc *> withdrawAcc;
    std::vector<DepositOnlyAcc *> depositOnlyAcc;

    withdrawAcc.push_back(new CurrentAccount());
    withdrawAcc.push_back(new SavigAccount);
    depositOnlyAcc.push_back(new FixedDepositAcc());

    BankClient *client = new BankClient(depositOnlyAcc, withdrawAcc);
    client->processTransection();

    return 0;
}
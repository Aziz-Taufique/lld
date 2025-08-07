#include <iostream>

// Abstraction (Interface)
class Database
{
public:
    virtual void save(std::string data) = 0;
};

// my-sql (low-level module).
class MySqlDatabase : public Database
{
public:
    void save(std::string data) override
    {
        std::cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << std::endl;
    }
};

// mongodb (low-level module)
class Mongodb : public Database
{
public:
    void save(std::string data) override
    {
        std::cout << "Executing Mongodb function : INSERT INTO users VALUES('" << data << "');" << std::endl;
    }
};

class UserService
{
    Database *db; // Dependency injection

public:
    UserService(Database *db)
    {
        this->db = db;
    };

    void storeUser(std::string user)
    {
        db->save(user);
    }
};

int main()
{
    Database *sql = new MySqlDatabase();
    Database *mongo = new Mongodb();
    UserService *userService = new UserService(mongo);
    userService->storeUser("aziz");
}
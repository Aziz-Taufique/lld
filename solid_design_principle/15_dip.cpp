#include <iostream>

// Dependency inversion principle
// High level module should not depend on low level module but rether both should depend on abstraction.

class MySqlDatabase
{
public:
    void saveToSql(std::string data)
    {
        std::cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << std::endl;
    }
};

class MongoDb
{
public:
    void saveToMongoDb(std::string data)
    {

        std::cout << "Executing Mongodb function : INSERT INTO users VALUES('" << data << "');" << std::endl;
    }
};

class UserService
{
    MySqlDatabase *sql;
    MongoDb *mongo;

public:
    void storeUserToSql(std::string user)
    {
        // MY-sql specific code.
        sql->saveToSql(user);
    };

    void storeUserToMongoDb(std::string user)
    {
        // mongodb specific code.
        mongo->saveToMongoDb(user);
    }
};

int main()
{
    UserService *userService = new UserService();
    userService->storeUserToMongoDb("Aziz");
    userService->storeUserToSql("Taufique");
    return 0;
}
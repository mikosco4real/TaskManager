#pragma once

#include <iostream>
#include <ctime>

class User 
{
    private:
    std::string password;
    std::string file_name{"users.csv"};

    public:
    int id;
    std::string firstname;
    std::string lastname;
    std::string username;
    std::string email;
    std::string phone;
    time_t created_at;

    User(std::string firstname, std::string lastname, std::string username, std::string email, std::string phone, std::string password);

    ~User();

    std::string getPassword()
    {
        return password;
    }

};
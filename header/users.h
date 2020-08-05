#pragma once

#include <iostream>
#include <ctime>

class User
{
    private:
    std::string password;

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

};
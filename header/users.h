#pragma once
#include "../src/FieldsValidator.cpp"
// #include "FieldsValidator.cpp"
// #include "model.h"
#include <iostream>
#include <ctime>

class User : public FieldsValidator
{
private:

public:
    int user_id;
    std::string firstName;
    std::string lastName;
    std::string username;
    std::string email;
    std::string password;
    std::string phone;
    std::string address;
    time_t created_at;

    User(std::string afirstName, std::string alastName,
        std::string ausername, std::string aemail, std::string apassword,
        std::string aphone, std::string aaddress, time_t created_at);
    ~User();
    
    void registerUser();
    void update();
    void getUserInfo();
    void resetPassword();
    void updatePassword();
};


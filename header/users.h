#pragma once
#include "FieldsValidator.cpp"
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
    /*
    void setFirstName(std::string);
    void setLastName(std::string);
    void setUsername(std::string);
    void setEmail(std::string);
    void setPassword(std::string);
    void setPhone(std::string);
    void setAddress(std::string);
    void setCreatedAt(time_t);

    void getAge(int);
    void getFirstName(std::string);
    void getLastName(std::string);
    void getUsername(std::string);
    void getEmail(std::string);
    void getPassword(std::string);
    void getPhone(std::string);
    void getAddress(std::string);
    */

    void registerUser();
    void update();
    void getUserInfo();
    void resetPassword();
    void updatePassword();
};


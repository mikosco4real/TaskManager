#ifndef USERS_H
#define USERS_H

#pragma once
#include "../src/FieldsValidator.cpp"
//#include "FieldsValidator.cpp"


#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip> 
#include <unordered_map>

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
    //to search data
    //to search data
    std::string strArray[8] = { "user_id", "firstName", "lastName", "username", "email", "password","phone", "address" };

    User(std::string afirstName, std::string alastName,
        std::string ausername, std::string aemail, std::string apassword,
        std::string aphone, std::string aaddress, time_t created_at);
    ~User();
    
    int registerUser();
    void update();
    //void getUserInfo();
    std::unordered_map<string, string> getUserInfo(int seachType);
    bool processUpdating(std::unordered_map<string, string>& mapping);
    void resetPassword();
    void updatePassword();
};

#endif // !USERS_H
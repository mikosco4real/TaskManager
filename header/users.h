#ifndef USERS_H
#define USERS_H
#pragma warning(disable : 4996)
#pragma once
#include "../src/FieldsValidator.cpp"
// #include "FieldsValidator.cpp"

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip> 
#include <unordered_map>
#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */


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

    User() = default;

    User(std::string afirstName, std::string alastName,
        std::string ausername, std::string aemail, std::string apassword,
        std::string aphone, std::string aaddress, time_t created_at);
    ~User();
    
    int registerUser();
    void update();
    std::unordered_map<string, string> getUserInfo(int seachType);
    bool processUpdating(std::unordered_map<string, string>& mapping);
    void resetPassword();
    void updatePassword();
};


class FormatUserDate{
public:
    string convertDateToString(time_t time_creation);
    time_t convertStringDateToTime_t(string time_creation);
};

#endif // !USERS_H
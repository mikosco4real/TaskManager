/**
 * @file FieldsValidator.cpp
 *
 * @brief This file has the validation of each of the 
 * fields that the application manages
 *
 * @author Fernando Quiros
 * @version 1 o8/08/2020
 * Contact: fernandoquiros@lsst.org
 *
 */
#pragma once
#include <iostream>
#include <string>
//#include <stdio.h>
#include "Password.cpp"
using namespace std;
/**
 * Class FieldsValidator
 *
 * Defines all the functions to validate the fields
 * that the user uses
 */

class FieldsValidator {
public:
    struct UserFields
    {
        string firstname; //firstName
        string lastname; //lastName
        string username; //username
        string email; //email
        string passvalue;
        string phone;
        string address;

    };
    

    /**
      * FieldsValidator::validatename
      * The function validates that the name has the right lengh
      * and is not empty
      *
      * @return string value of the name
      */
    string validatename() {
        UserFields cust;
        bool isValid;
        do {
            cin.clear();
            cout << "Please enter First Name: ";
            cin >> cust.firstname;
            //Verifiy that First name is not empty
            if (cust.firstname.length() > 2) {
                isValid = true;
            }
            else {
                isValid = false;
                cin.clear();
                // cin.ignore(INT_MAX, '\n');
                cout << "First name is required. Retry.\n";
            }
        } while (!isValid);

        return cust.firstname;
    }
    

    /**
      * FieldsValidator::validteLastname
      * The function validates that the last name has the right lengh
      * and is not empty
      *
      * @return string value of the last name
      */
    string validteLastname() {
        UserFields cust;
        bool isValid = true;
        do {
            cout << "Please enter Last Name: ";
            cin >> cust.lastname;
            //Verifiy that Last Name is not empty
            if (cust.lastname.length() > 0) {
                isValid = true;
            }
            else {
                isValid = false;
                cin.clear();
                // cin.ignore(INT_MAX, '\n');
                cout << "Last name is required. Retry.\n";
            }
        } while (!isValid);

        return cust.lastname;
    }


    /**
      * FieldsValidator::validteUsername
      * The function validates that the username has the right lengh
      * and is not empty
      *
      * @return string value of the username
      */
    string validteUsername() {
        UserFields cust;
        bool isValid = true;
        do {
            cout << "Please enter Username: ";
            cin >> cust.username;
            //Verifiy that username is not empty
            if (cust.username.length() > 0) {
                isValid = true;
            }
            else {
                isValid = false;
                cin.clear();
                // cin.ignore(INT_MAX, '\n');
                cout << "Username is required. Retry.\n";
            }
        } while (!isValid);

        return cust.username;
    }

    /**
      * FieldsValidator::validateEmail
      * The function validates that the value of email is not empty
      *
      * @return string value of the email
      */
    string validateEmail() {
        UserFields cust;
        bool isValid = true;
        do {
            isValid = false;
            cout << "Enter Email: ";
            cin >> cust.email;
            //Verifiy that year is numeric
            cin.ignore(1);
            if (cin.good() && cust.email.length() > 0) {
                isValid = true;
            }
            else {
                cin.clear();
                // cin.ignore(INT_MAX, '\n');
                cout << "Email is required. Retry.\n";
            }
        } while (!isValid);

        return cust.email;
    }

    /**
      * FieldsValidator::validatePassword
      * The function validates if the password typed by the users has
      * the right format and has the right complexity
      *
      * @param string newpas it caontainns the value if the password is new
      * @return string value of the password
      */
    string validatePassword(string newpas) {
        UserFields cust;
        PasswordStatus ps;
        do
        {
            cout << "Please enter " + newpas + " password : ";
            cin >> cust.passvalue;
            ps.checkValidity(cust.passvalue);
            if (!ps.IsTotalyValid()) {
                ps.ShowStatus();
            }
        } while (!ps.IsTotalyValid());
     
        return cust.passvalue;
    }

    
    
    /**
      * FieldsValidator::validtePhone
      * The function validates that the phone has the right lengh
      * and is not empty
      *
      * @return string value of the phone
      */
    string validtePhone() {
        UserFields cust;
        bool isValid = true;
        do {
            cout << "Please enter phone: ";
            cin >> cust.phone;
            //Verifiy that phone is not empty
            if (cust.phone.length() > 0) {
                isValid = true;
            }
            else {
                isValid = false;
                cin.clear();
                // cin.ignore(INT_MAX, '\n');
                cout << "Phone is required. Retry.\n";
            }
        } while (!isValid);

        return cust.phone;
    }

    /**
      * FieldsValidator::validteAddress
      * The function validates that the address has the right lengh
      * and is not empty
      *
      * @return string value of the address
      */
    string validteAddress() {
        UserFields cust;
        bool isValid = true;
        do {
            cout << "Please enter Address: ";
            cin >> cust.address;
            //Verifiy that address is not empty
            if (cust.address.length() > 0) {
                isValid = true;
            }
            else {
                isValid = false;
                cin.clear();
                // cin.ignore(INT_MAX, '\n');
                cout << "Address is required. Retry.\n";
            }
        } while (!isValid);

        return cust.address;
    }
};
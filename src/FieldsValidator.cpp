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
    string validatename(string newvalue) {
        UserFields cust;
        bool isValid;
        do {
            cin.clear();
            cout << "Please enter " + newvalue + " First Name: ";
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
    string validteLastname(string newvalue) {
        UserFields cust;
        bool isValid = true;
        do {
            cout << "Please enter " + newvalue + " Last Name: ";
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
    string validteUsername(string newvalue) {
        UserFields cust;
        bool isValid = true;
        do {
            cout << "Please enter " + newvalue + " Username: ";
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
    string validateEmail(string newvalue) {
        UserFields cust;
        bool isValid = true;
        do {
            isValid = false;
            cout << "Enter " + newvalue + " Email: ";
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
        {    // time_t t = time(0);

    // cout << "Initial time" << t <<endl;
    // FormatUserDate objConverter; 
    // string stringdate = objConverter.convertDateToString(t);
    // cout << "String time" << stringdate << endl;


    // time_t lastTime = objConverter.convertStringDateToTime_t(stringdate);
    // cout << "time back to time_t format " << lastTime << endl;
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
    string validtePhone(string newvalue) {
        UserFields cust;
        bool isValid = true;
        do {
            cout << "Please enter " + newvalue + " phone: ";
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
    string validteAddress(string newvalue) {
        UserFields cust;
        bool isValid = true;
        do {
            cout << "Please enter " + newvalue + " Address: ";
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

    //ADD FIELDS FOR TASK

    /**
      * FieldsValidator::validteTaskName
      * The function validates that the task name has the right lengh
      * and is not empty
      *
      * @return string value of the task name
      */
    string validteTaskName(string newvalue) {
      
        string task_name;

        bool isValid = true;
        do {
            cout << "Please insert the task name: ";
            cin >> task_name;
            //Verifiy that task_name is not empty
            if (task_name.length() > 0) {
                isValid = true;
            }
            else {
                isValid = false;
                cin.clear();
                cout << "Task name is required. Retry.\n";
            }
        } while (!isValid);

        return task_name;
    }

    /**
      * FieldsValidator::validateAssignedTo
      * The function validates that the id assignedto has the right lengh
      * and is not empty
      *
      * @return string value of the assignedto
      */
    string validateAssignedTo(string newvalue) {

        string assignedto;

        bool isValid = true;
        do {
            cout << "Please insert the ID of the user whom you wish to assign the task to: ";
            cin >> assignedto;
            //Verifiy that id is not empty
            if (assignedto.length() > 0) {
                isValid = true;
            }
            else {
                isValid = false;
                cin.clear();
                cout << "The field is required. Retry.\n";
            }
        } while (!isValid);

        return assignedto;
    }
    
   
    /**
      * FieldsValidator::validateTaskDue
      * The function validates that the due date has the right lengh
      * and is not empty
      *
      * @return string value of the assignedto
      */
    string validateTaskDue(string newvalue) {

        string taskduedate;

        bool isValid = true;
        do {
            cout << "Please insert the task due date and time (Format DD-MM-YYYY):\n";
            cin >> taskduedate;
            //Verifiy that taskduedate is not empty
            if (taskduedate.length() > 0) {
                isValid = true;
            }
            else {
                isValid = false;
                cin.clear();
                cout << "The field is required. Retry.\n";
            }
        } while (!isValid);

        return taskduedate;
    }



    //ADD FIELDS FOR TASK GROUP



    //ADD FIELDS FOR TASK GROUP MAP




};
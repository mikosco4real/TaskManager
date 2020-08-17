#include <iostream>
#include "model.h"
#include <vector>
#include <algorithm>
#include "view.h"


int main()
{
    // time_t t = time(0);

    // cout << "Initial time" << t <<endl;
    // FormatUserDate objConverter; 
    // string stringdate = objConverter.convertDateToString(t);
    // cout << "String time" << stringdate << endl;


    // time_t lastTime = objConverter.convertStringDateToTime_t(stringdate);
    // cout << "time back to time_t format " << lastTime << endl;

    
    /*
    //Insert User
    User InstanceInsert("", "", "", "", "", "", "", t);
    int idForThisUser = InstanceInsert.registerUser();

    cout << "User ID" << idForThisUser <<endl;

    /*
    //method for Update user working
    //User InstanceUs("", "", InstanceInsert.username, "", "", "", "", t);
    //InstanceUs.update();

    //For login, it search data
    std::cout << "UserName" << InstanceInsert.username << "--PASS --" << InstanceInsert.password << std::endl;
    User InstanceLogin("", "", InstanceInsert.username, "", InstanceInsert.password, "", "", t);
    //parameter two means it is going to verify username and password
    unordered_map<string, string> userExist = InstanceLogin.getUserInfo(2);
    if (userExist["found"] == "1") {
        std::cout << "Welcome to the system "+ userExist["firstname"] +" "+ userExist["lastname"] << std::endl;
    }

    */
   Views view;
   std::string command{};
   view.header();
   view.menu();
//    std::tolower(command);

    while (true){
        std::cout << "Option >> ";
        std::getline(std::cin, command);
        std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c){ return std::tolower(c); });
        
        if (command == "quit" || command == "q"){
            // End the program
            break;
        }
        else
        {
            view.router(command);
        }
        
    }

    return 0;
}
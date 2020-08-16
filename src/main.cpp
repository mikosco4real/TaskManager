#include <iostream>
#include "model.h"
#include <vector>
#include <algorithm>
#include "view.h"


int main()
{
    time_t t = time(NULL);

    /*
    
    //Insert User
    User InstanceInsert("", "", "", "", "", "", "", t);
    int idForThisUser = InstanceInsert.registerUser();
    
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

   Session s;
   s.start();

    return 0;
}
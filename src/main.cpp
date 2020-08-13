#include <iostream>
#include "model.h"
#include <vector>
#include <algorithm>




int main()
{
    time_t t = time(NULL);
    
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

    /*
    std::cout << "Welcome to my C++ Program" << std::endl;
    // time_t t = time(NULL);
    UserModel user;
    User u("Michael", "Okolo", "mokolo", "mokolo@example.com", "p12345", "0123456789", "Ultimo Torrens University", t);
    User u2("Fernando", "Dayan", "fdayan", "fdayan@example.com", "p12345", "0123456789", "Ultimo Torrens University", t);
    u.user_id = 1;
    u2.user_id = 2;

    user.save(u);
    user.save(u2);

    for (auto x : user.all())
    {
        if (x.username == "fdayan" && x.password == "p12345") {
            std::cout << x.username << ", " << x.lastName << ", " << x.firstName << std::endl;
        }
    }*/
    return 0;
}
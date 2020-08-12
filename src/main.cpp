#include <iostream>
#include "model.h"
#include <vector>
#include <algorithm>

int main()
{
    time_t t = time(NULL);
    User InstanceUs("", "", "", "", "", "", "", t);
    InstanceUs.registerUser();

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
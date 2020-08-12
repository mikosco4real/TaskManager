#include <iostream>
#include "model.h"
#include <vector>
#include <algorithm>

int main()
{
    time_t t = time(NULL);
    User InstanceUs("", "", "", "", "","", "", t);
    InstanceUs.registerUser();
    
    std::cout << "Welcome to my C++ Program" << std::endl;
    time_t t = time(NULL);
    UserModel user;
    User u("Michael", "Okolo", "mokolo", "mokolo@example.com", "p12345", "0123456789", "Ultimo Torrens University", t);
    u.user_id = 1;

    user.save(u);

    for(auto x : user.all())
    {
        std::cout << x.created_at << ", " << x.lastName << ", " << x.firstName << std::endl;
    }
    return 0;
}
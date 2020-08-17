#include "view.h"
#include "model.h"

void Session::start()
{
    if(login()){
        std::cout << "Authentication is successful" << std::endl;
        active = true;
    }
    else{
        std::cout << "Username or password is incorrect" << std::endl;
    }
}


void Session::end()
{
    std::cout << time(&start_time) << std::endl;
}


bool Session::status()
{
    std::cout << time(&start_time) << std::endl;
}


bool Session::login()
{
    UserModel u;
    std::vector<User> all = u.all();
    std::string username, password;

    std::cout << "Username: ";
    std::getline(std::cin, username);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    auto user_it = std::find_if(all.begin(), all.end(), [username, password] (User obj){
        return obj.username == username && obj.password == password;
    });

    return user_it != all.end();
}
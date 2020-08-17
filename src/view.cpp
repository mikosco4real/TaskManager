#include "view.h"
#include "model.h"

void Session::start()
{
    std::cout << std::endl;
    if(login()){
        active = true;
        start_time = time(NULL);
        std::cout << "You are now logged in as " << user.username << std::endl;
    }
    else{
        std::cout << "Username or password is incorrect" << std::endl;
    }
}


void Session::end()
{
    user = User();
    active = false;
    std::cout << "You have been logged out successfully" << std::endl;
}


bool Session::status()
{
    return active;
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

    if (user_it != all.end()){
        user = *user_it;
    }

    return user_it != all.end();
}


// Views starts here

void Views::header(){
    system("cls");
    std::cout << ":::::::::::::::::::::::::::::::::::::::  Welcome to TaskManager  ::::::::::::::::::::::::::" << std::endl; 
}

void Views::menu(){
    std::cout << std::endl;
    std::cout << "Options" << std::endl;
    std::cout << "login - provides a page to login to the system" << std::endl;
    std::cout << "logout - Logs the user out of the system" << std::endl;
    std::cout << "Quit - To terminate the program" << std::endl;
    std::cout << std::endl;
}

void Views::router(std::string command){
    if(command == "login"){
        login();
    }
    else if (command == "logout"){
        // TODO:: Log the user out
    }
    else{
        std::cout << "Invalid Command!!!" << std::endl;
    }
}

void Views::login(){
    session.start();
}
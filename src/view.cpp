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


// Views starts here

void Views::header(){
    system("cls");
    std::cout << "::::::::::::::::::::::: Welcome to TaskManager :::::::::::::::::::::::" << std::endl; 
}

void Views::menu(){
    std::cout << std::endl;
    std::cout << "Options" << std::endl;
    std::cout << "Login - Provides a page to login to the system" << std::endl;
    std::cout << "Logout - Logs the user out of the system" << std::endl;
    std::cout << "Register User - Registers a new user in the system" << std::endl;
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
    Session s;
    s.start();
}

void Views::logout(){
    Session s;
    s.end();
}

void registerUser(){

}
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
    std::cout << "Create TaskGroup - Creates a task group" << std::endl;
    std::cout << "Add User - Adds a new user to the task group" << std::endl;
    std::cout << "Create Task - Creates a task" << std::endl;
    std::cout << "Assign Task - Assigns task to a member of the task group" << endl;
    std::cout << "Complete Task - Changes the status of the task" << endl;
    std::cout << "Update Profile - Updates the user profile" << endl;
    std::cout << "Get User Info - Retrieves user information" << endl;
    std::cout << "Get TaskGroup - Views information of task group" << endl;
    std::cout << "View Task - Views available tasks" << endl;
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

void Views::registerUser(){
    User u;
    u.registerUser();
}

void Views::createTaskGroup(){
    TaskGroup t;
    t.createTaskGroup();
}

void Views::addUser(){
    TaskGroup t;
    t.addUser();
}

void Views::createTask(){
    Task t;
    t.createTask();
}

void Views::assignTask(){
    Task t;
    t.assignTask();
}

void Views::completeTask(){
    Task t;
    t.completeTask();
}

void Views::updateProfile(){
    User u;
    u.update();
}

void Views::leaveGroup(){
    TaskGroup l;
    l.leaveGroup();
}

void Views:: getUserInfo(){
    User u;
    u.getUserInfo(); //return vector???
}

void Views::getGroups(){
    TasksGroupMap t;
    t.getGroups();
}

void Views::viewTask(){
    Task t; //create header for Task.cpp
    t.viewTask();
}
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
    std::cout << "::::::::::::::::::::::: Welcome to TaskManager :::::::::::::::::::::::" << std::endl; 
}

void Views::menu(){
    std::cout << std::endl;
    std::cout << "Options" << std::endl;
    std::cout << "Login - Provides a page to login to the system" << std::endl;
    std::cout << "Logout - Logs the user out of the system" << std::endl;
    std::cout << "Register User - Registers a new user in the system" << std::endl;
    std::cout << "Create TaskGroup - Creates a task group" << std::endl;
    std::cout << "Update Profile - Updates the user profile" << endl;
    std::cout << "Get TaskGroup - Views information of task group" << endl;
    std::cout << "Create Task - Creates a task" << std::endl;
    std::cout << "View Task - Views available tasks" << endl;
    std::cout << "Assign Task - Assigns task to a member of the task group" << endl;
    std::cout << "Complete Task - Changes the status of the task" << endl;
    std::cout << "Add User - Adds a new user to the task group" << std::endl;
    std::cout << "Get User Info - Retrieves user information" << endl;
    std::cout << "Quit - To terminate the program" << std::endl;
    std::cout << std::endl;
}

void Views::router(std::string command){
    if(command == "login"){
        login();
    }
    else if (command == "logout"){
        logout();
    }
    else if (command == "register user"){
        registerUser();
    }
    else if (command == "create taskgroup"){
        createTaskGroup();
    }
    else if (command == "update profile"){
        updateProfile();
    }
    else if (command == "get taskgroup"){
        getGroups();
    }
    else if (command == "create task"){
        createTask();
    }
    else if (command == "view task"){
        viewTask();
    }
    else if (command == "assign task"){
        assignTask();
    }
    else if (command == "complete task"){
        completeTask();
    }
    else if (command == "add user"){
        addUser();
    }
    else if (command == "get user info"){
        getUserInfo();
    }
    else{
        std::cout << "Invalid Command!!!" << std::endl;
    }
}

void Views::login(){
    session.start();
}

void Views::logout(){
    session.end();
}

void Views::registerUser(){
    user.registerUser();
}

void Views::createTaskGroup(){
    taskgroup.createTaskGroup();
}

void Views::addUser(){
    taskgroup.addUser();
}

void Views::createTask(){
    task.createTask();
}

void Views::assignTask(){
    task.assignTask();
}

void Views::completeTask(){
    task.completeTask();
}

void Views::updateProfile(){
    user.update();
}

void Views::leaveGroup(){
    taskgroup.leaveGroup();
}

void Views:: getUserInfo(){
    user.getUserInfo(); //return vector???
}

void Views::getGroups(){
    taskgroupmap.getGroups();
}

void Views::viewTask(){
    task.viewTask();
}
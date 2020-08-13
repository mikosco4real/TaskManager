#include <iostream>
#include <string>
#include <ctime>
#include <vector>

int id_task_group;
int id_task;
std::string task_name;
int assigned_to;
std::string created_by;
std::string created_at;
std::string due_date;
std::string status;

void createTask(){
    std::cout << "Please insert the task name\n";
    std::cin >> task_name; // limit quantity of characters?
    created_by = User.firstName;
    created_at = time_t;
}

void completeTask(){
}

void acceptTask(){
}

void approveTask(){
}
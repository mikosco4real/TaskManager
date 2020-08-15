#include <iostream>
#include <string>
#include <ctime>
#include <vector>

int id_task_group;
int id_task;
std::string task_name;
int assigned_to;
std::string created_by;
time_t created_at;
std::string due_date;
std::string status;

// modification test
//Diego's comment

void createTask(){
    std::cout << "Please insert the task name\n";
    std::cin >> task_name; // limit quantity of characters?
    created_by = User.firstName;
    created_at = time(0);
}

void completeTask(){
}

void acceptTask(){
}

void approveTask(){
}
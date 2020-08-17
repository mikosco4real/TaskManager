#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "../src/FieldsValidator.cpp"
// #include "FieldsValidator.cpp"

class Task : public FieldsValidator {

public:
    int id_task;
    std::string task_name;
    std::string assigned_to;
    std::string due_date;
    std::string created_by;
    time_t task_created_at;
    std::string status;
    
    std::vector<std::string> task_status{ "assigned", "accepted", "declined", "completed" };

    void createTask();

    void completeTask();

    void acceptTask();

    void approveTask();
};
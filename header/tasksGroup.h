#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "model.h"
#include "users.h"
using namespace std;

class TaskGroup {
private:
public:

    int id_task_group;
    int user_id;
    string name;
    int created_by;
    std::vector<User> all_users;

    TaskGroup();
    ~TaskGroup();

    void createTaskGroup();

    void leaveGroup();

    void addUser(){
        UserModel user;
        all_users.push_back(user.all()[7]);
    };
    void view_tasks();

};


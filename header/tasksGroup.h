#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "model.h"
#include "users.h"
using namespace std;

#include "../src/FieldsValidator.cpp"
//#include "FieldsValidator.cpp"

class TaskGroup : public FieldsValidator {
private:
public:

    int id_task_group = 0;
    int user_id = 0; //user admin id
    string name; //name of task group
    int created_by = 0; 
    std::vector<User> all_users;

    TaskGroup(int idtaskgroup, int userid, string nameUs,  int createdby);
    ~TaskGroup();

    void createTaskGroup();
    void leaveGroup();
    void addUser(int task_group_id);
    void view_tasks();

};


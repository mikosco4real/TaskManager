#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class TaskGroup {
private:
public:

    int id_task_group;
    int user_id;
    string name;
    int created_by;

    TaskGroup();
    ~TaskGroup();

    void createTaskGroup();

    void leaveGroup();

    void addUser();

};
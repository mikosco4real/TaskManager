#pragma once
//#include "../src/FieldsValidator.cpp"
#include "FieldsValidator.cpp"
#include "model.h"
#include <iostream>

class taskGroup : public FieldsValidator
{
private:

public:
    int taskgroup_id;
    int user_id;
    std::string name;
    int created_by;

    taskGroup(std::string name);
    ~tasGroup();
    
    void createtaskGroup();
    void leaveGroup();
    void addUser();
};
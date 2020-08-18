#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "users.h"
#include "tasks.h"
#include "tasksGroup.h"
#include "tasksGroupMap.h"
#include <ctime>

class BaseModel
/*
    This is a base class that defines how data is saved to disk.
    It contains methods that writes data to disk in CSV format and retrieves the items back as vectors.
    To use this object, you have to initialize it with a filename and then use any method below to write or retrieve item to or from the specified filename.

    Eg. BaseModel CSV(filename);

    To save a vector of strings to CSV file you simply call the save method as below.
    CSV.save(vector_of_strings);

    To retrieve items in the form of vector of vector of strings you simply call the load method without passing any arguments like below
    std::vector<std::vector<std::string>> data = CSV.load();
*/
{
   public:
   std::string filename {};
   std::fstream file;
   BaseModel(std::string filename) : filename(filename) {
       // Open file for read and write operations
       file.open(filename, std::fstream::app | std::fstream::out | std::fstream::in | std::fstream::binary);
   }

   // The save method saves data to disk using the CSV format. Input argument is a vector of strings
   bool save(std::vector<std::string>& record);

   // Loads data from disk. You can store the value in a vector of vector of strings as described above
   std::vector<std::vector<std::string>> load();
};


class UserModel
/*
    This is a model for handling the user objects. It writes user objects to disk in a CSV format and retrieves user objects from disk. It comes with specialised
    methods for recreating user objects from disk. To use this object you first need to initialize it and then use any of its member methods to perform your desired
    action.
    EG. UserModel model;
    model.save(user obj);
    std::vector<User> all_users = model.all();
*/
{
    public:
    std::string filename = "users.csv";

    // Serializes User Objects to Vectors
    std::vector<std::string> users2vector(User obj);

    // Serializes vector of strings back to user objects
    User vector2user(std::vector<std::string>& data);

    // Writes a given user object to disk.
    bool save(User obj){
        std::vector<std::string> user_data = users2vector(obj);
        BaseModel CSV(filename);
        return CSV.save(user_data);
    }

    // Used to save many user objects to disk. however it recreates the file since it first deletes the files before writing the user objects
    bool save_all(std::vector<User>& u){
        bool flag;
        remove(filename.c_str());
        for(User x : u){
            flag = save(x);
        }
        return flag;
    }

    std::vector<User> all(){
        BaseModel CSV(filename);
        std::vector<std::vector<std::string>> users = CSV.load();
        std::vector<User> u;

        for(auto x : users)
        {
            User obj = vector2user(x);
            u.push_back(obj);
        }

        std::sort(u.begin(), u.end(), [](User a, User b)
        {
            return a.user_id < b.user_id;
        });
        return u;
    }

    bool update(User& obj){
        // Updates a users record on the file
        std::vector<User> all_users = all();
        auto obj_it = std::find_if(all_users.begin(), all_users.end(), [obj] (User u) {
            return u.user_id == obj.user_id;
        });
        if(obj_it == all_users.end()){
            // Match not found
        }
        else{
            all_users.erase(obj_it);
            all_users.push_back(obj);
        }
        return save_all(all_users);
    }

    int getLastId(){
        // Returns the last Id created for a User.
        return all().back().user_id;
    }
};


// New Object - Model for Managing TaskGroupMap.
class TaskGroupMapModel
{
    public:
    std::string filename = "taskgroupmap.csv";

    // Serializations
    std::vector<std::string> data2vector(TasksGroupMap& obj);
    TasksGroupMap vector2data(std::vector<std::string>& obj);

    bool save(TasksGroupMap& obj);
    bool save_all(std::vector<TasksGroupMap>& obj);
    std::vector<TasksGroupMap> all();
    bool update(TasksGroupMap& obj);
    int getLastId();
    bool deleteData(TasksGroupMap& obj);
};


// New Object - Model for Managing TaskGroup
class TaskGroupModel
{
    public:
    std::string filename = "taskgroup.csv";

    // Serializations
    std::vector<std::string> data2vector(TaskGroup& obj);
    TaskGroup vector2data(std::vector<std::string>& obj);

    bool save(TaskGroup& obj);
    bool save_all(std::vector<TaskGroup>& obj);
    std::vector<TaskGroup> all();
    bool update(TaskGroup& obj);
    int getLastId();
    bool deleteData(TaskGroup& obj);
};
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "users.h"
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

    bool update(){
        // TODO:: Create update definition here
        return true;
    }

    int getLastId(){
        // TODO:: Return the last id of a saved user.
        return all().back().user_id;
    }
};
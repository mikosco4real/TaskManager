#pragma once
#include <iostream>
#include <fstream>

class BaseModel
/*
    This is a base class that defines how data is saved to disk.
*/
{
   public:
   std::string filename{};
   std::fstream file;

   BaseModel(std::string filename) : filename(filename){
       // Open file for read and write operations
       file.open(filename, std::fstream::app | std::fstream::out | std::fstream::in);
   }
   ~BaseModel(){
       // Close file when this object is destroyed
       file.close();
   }
};


class UserModel : public BaseModel
{
    public:
    UserModel() : BaseModel{"users.csv"}{
        std::cout << "UserModel Object Constructed!" << std::endl;
    }
    ~UserModel(){
        // TODO: Destructor goes here;
    }
};
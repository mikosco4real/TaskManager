#pragma once
#include <iostream>
#include <fstream>

class BaseModel
{
   public:
   std::string filename{};
   std::fstream file;

   BaseModel(std::string filename) : filename(filename){
       file.open(filename, std::fstream::app | std::fstream::out | std::fstream::in);
   }
   ~BaseModel(){
       file.close();
   }
};


class UserModel : public BaseModel
{
    public:
    UserModel() : BaseModel{"users.csv"}{
        std::cout << "UserModel Object Constructed!" << std::endl;
    }
    ~UserModel();
};
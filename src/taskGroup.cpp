#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int id_task_group;
int user_id;
string name;
int created_by;

void createTaskGroup()
{
    system("cls");
    cout << "Welcome to the Task Group Menu!\n\nPlease name New Task Group:" << endl;
    getline (cin,name);
    ofstream myfile("TaskGroup.csv");
    myfile << name;
    myfile.close();
}

void leaveGroup(){
}

void addUser()
{
    system("cls");
    ofstream myfile("TaskGroup.csv");
    cout << "Please, introduce the names of the group´s members: " << endl;
    myfile.seekp(0,ios::end);
    vector<string> user;
    //user.push_back();
    for (int i = 0; i < user.size(); i++)
    cout << user[i] << endl;
    myfile.close();
}
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

/*int id_task_group;
std::string task_name;
std::string assigned_to;
std::string created_by;
time_t created_at;
std::string due_date;
std::string status;
*/

int id_task = 0;

std::vector<std::string> task;
/*
task[0] = ID of the task
task[1] = Task name
task[2] = Name of the user who created the task
task[3] = Name of the user who is going to be assigned the task
task[4] = Date and time of task creation
task[5] = Date and time when the task is due
task[6] = Status of the task
*/

std::vector<std::string> task_status{"assigned", "accepted", "declined", "completed"};

void createTask(){
    //available only if the user is group admin
    id_task++;
    task[0] = id_task;

    std::cout << "Please insert the task name:\n";
    std::cin >> task[1];

    // task[2] = User.firstName;

    std::cout << "Please insert the ID of the user whom you wish to assign the task to:\n";
    std::cin >> task[3];

    // task[4] = time_t;
    

    std::cout << "Please insert the task due date and time:\n";
    std::cin >> task[5]; //format

    task[6] = task_status[0];
}

int choice = 0;

do {
    std::cout << "1. Create task\n";
    std::cout << "2. Delete task\n";
    std::cout << "3. Edit task\n";
    std::cout << "4. Accept task\n";
    std::cout << "5. Decline task\n";
    std::cout << "6. Mark task as complete\n";

    switch (menu){
        case 1:
            createTask();
            break;
        case 2:
            deleteTask();
            break;
        case 3:
            editTask();
    }
    
    
    
    }

void deleteTask(){
    //available only if the user is group admin
    id_task = 0;
    std::cout << "Please insert the number of the task you wish to delete:\n";
    std::cin >> id_task;
}

void editTask(){
    //available only if the user is group admin
    id_task = 0;
    std::cout << "Please insert the number of the task you wish to edit:\n";
    std::cin >> id_task;
}

void acceptTask(){
    id_task = 0;
    std::cout << "Please insert the number of the task you wish to accept:\n";
    std::cin >> id_task;
}

void declineTask(){
    id_task = 0;
    std::cout << "Please insert the number of the task you wish to decline:\n";
    std::cin >> id_task;
}

void completeTask(){
    int task_number;
    std::cout << "Please insert the number of the task you wish to mark as completed:\n";
    std::cin >> task_number;
    task[task_number] = task_status[3];
}
#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "users.h"

class Session
{
    public:
    bool active = false;
    time_t start_time, last_active_time;
    User user;
    FormatUserDate fmt;
    Session() = default;
    void start();
    void end();
    bool status();
    bool login();
};


class Views
{
    public:
    // Start Working on Views
    Session session;

    void header();
    void menu();
    void router(std::string command);
    void login();

    /*
        login
        logout -- Session u -- u.end()
        register user
        create taskgroup
        add users - to task group
        create tasks
        assign tasks
        mark tasks with status - task completed 
        task status 
        update user profile
        leave taskgroup
        view user info
        view Taskgroups
        view Tasks == taskgroup id or name




    */

};
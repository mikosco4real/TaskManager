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
    User u;
    Session() = default;
    void start();
    void end();
    bool status();
    bool login();
};


class Views
{
    // Start Working on Views
};
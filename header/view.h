#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

class Session
{
    public:
    bool active = false;
    time_t start_time, last_active_time;
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
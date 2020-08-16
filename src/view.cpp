#include "view.h"

void Session::start()
{
    std::cout << time(&start_time) << std::endl;
}


void Session::end()
{
    std::cout << time(&start_time) << std::endl;
}


bool Session::status()
{
    std::cout << time(&start_time) << std::endl;
}
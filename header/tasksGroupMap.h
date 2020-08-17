#pragma once
#include "users.h"
#include "tasksGroup.h"

class TasksGroupMap
{
public:

	int id_task_group_map = 0;
	int id_user = 0;
	int id_task_group = 0;
	//User us;
	//TaskGroup tg;
	TasksGroupMap();
	~TasksGroupMap();
	void createGroupMap();
	void getUsers();
	void getGroups();
	void disableMap();


	void getGroups();

private:

};

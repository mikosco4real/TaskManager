#include "tasksGroup.h"
#include "tasksGroupMap.h"
#include "model.h"


TaskGroup::TaskGroup(int idtaskgroup, int userid, string nameUs, int createdby) {
	id_task_group = idtaskgroup;
	user_id = userid;
	name = nameUs;
	created_by = createdby;
}
TaskGroup::~TaskGroup() {
	
}

void TaskGroup::createTaskGroup()
{
	//ask for task group name
	name = validateTaskGroupName("");

	//Class that shoud be added by Michael to handle TaskGroup file
	//--TaskGroupModel taskMdl;
	//--int lastId = taskMdl.getLastId(); Michale returns last Id
	
	//Save data in csv using model, RETURNING THE ID OF THE TASK GROUP
	//generates user object with the data
	//id_task_group = lastId + 1;

	//user_id, it should be possible to get it from the session
	
	TaskGroup objTs(id_task_group, user_id, name, user_id);
	

	//Save data in file calling the method Michael
	//taskMdl.save(objTs);

	//Then ask for users to add to the group
	addUser(id_task_group);

}

void TaskGroup::leaveGroup() {

}

void TaskGroup::addUser(int task_group_id)
{
	//Ask for username or email to add
	TasksGroupMap objTasksGroupMap;
	objTasksGroupMap.id_task_group_map = 0;
	objTasksGroupMap.id_user = 0;
	objTasksGroupMap.id_task_group = 0;
	
	time_t t = time(0);
	unordered_map<string, string> mappinguser;

	//Ask for unsername to add
	do {
		//find user
		string usernametoadd = validateusernameforTaskGroup("");
		User us("", "", usernametoadd, "", "", "", "", t);
		mappinguser = us.getUserInfo(1);
		if (mappinguser["found"] == "1") {
			cout << " Username found!" << endl;
			//should call the michael model and asociate this user to the task group
			
			//--TaskGroupMapModel taskMdlGp; Michael creates a model to handle tasksgroup map
			//--int lastId = taskMdlGp.getLastId(); Michael return last id of task group map

			int lastId = 0;
			objTasksGroupMap.id_task_group_map = lastId + 1;
			objTasksGroupMap.id_user = stoi(mappinguser["usersId"]);
			objTasksGroupMap.id_task_group = task_group_id;

			//Michael creates method to save data
			//taskMdlGp.save(objTasksGroupMap);
		}
		else { 
			cout << " Username not found!" << endl;
		}

	} while (mappinguser["found"] != "1");


	char c;
	cout << "Would you like add another user? (Y/N)? ";
	cin >> c;
	if (toupper(c) == 'Y') {
		addUser(task_group_id);
	}

}

void TaskGroup::view_tasks() {
	
}
#include "model.h"

bool BaseModel::save(std::vector<std::string>& record)
{
    if (!file.is_open()){
        std::cout << "File (" << filename << ") not found" << std::endl;
        return false;
    }
    else{
        std::stringstream lines("", std::ios::out | std::ios::app);
        int counter {0};
        for (std::string s : record){
            lines << s;
            if (counter < (record.size() - 1)){
                lines << ",";
            }
            counter++;
        }
        file << lines.str() << std::endl;
        file.close();
        
        return file.good();
    }
}

// Load all data from a given file
std::vector<std::vector<std::string>> BaseModel::load()
{
    std::vector<std::vector<std::string>> data;
    if (!file.is_open())
    {
        std::cout << "File (" << filename << ") not found" << std::endl;
    }
    else
    {
        std::string line;
        // Start Reading files from the first line
        file.seekg(0);
        while(getline(file, line))
        {
            std::vector<std::string> rows;
            std::string e;
            std::stringstream linestream(line);
            
            while(getline(linestream, e, ','))
            {
                rows.push_back(e);
            }
            data.push_back(rows);
            rows.clear();
        }
    }
    file.close();
    return data;
}

// Serialization of User attributes to vector
std::vector<std::string> UserModel::users2vector(User obj)
{
    std::vector<std::string> data;

    data.push_back(std::to_string(obj.user_id));
    data.push_back(obj.firstName);
    data.push_back(obj.lastName);
    data.push_back(obj.username);
    data.push_back(obj.email);
    data.push_back(obj.password);
    data.push_back(obj.phone);
    data.push_back(obj.address);
    data.push_back(std::to_string(obj.created_at));
    return data;
}

// DeSerialization of vectors to user attributes
User UserModel::vector2user(std::vector<std::string>& data)
{
    std::string user_id{data[0]}, firstname{data[1]}, lastname{data[2]}, username{data[3]}, email{data[4]}, password{data[5]}, phone{data[6]}, address{data[7]}, created_at{data[8]};
    time_t t = time(NULL);
    User obj(firstname, lastname, username, email, password, phone, address, t);
    obj.user_id = stoi(user_id);

    return obj;
}


// IMPLEMENTATIONS FOR TasksGroupMap STARTS HERE

std::vector<std::string> TaskGroupMapModel::data2vector(TasksGroupMap& obj){
    std::vector<std::string> data;

    data.push_back(std::to_string(obj.id_task_group));
    data.push_back(std::to_string(obj.id_user));
    data.push_back(std::to_string(obj.id_task_group_map));

    return data;
}


TasksGroupMap TaskGroupMapModel::vector2data(std::vector<std::string>& obj){
    TasksGroupMap tgm;
    tgm.id_task_group = stoi(obj[0]);
    tgm.id_user = stoi(obj[1]);
    tgm.id_task_group_map = stoi(obj[2]);

    return tgm;
}


bool TaskGroupMapModel::save(TasksGroupMap& obj){
    std::vector<std::string> data = data2vector(obj);
    BaseModel CSV(filename);
    return CSV.save(data);
}


bool TaskGroupMapModel::save_all(std::vector<TasksGroupMap>& obj){
    bool flag = false;
    remove(filename.c_str());
    for (auto data : obj){
        flag = save(data);
    }
    return flag;
}


std::vector<TasksGroupMap> TaskGroupMapModel::all(){
    BaseModel CSV(filename);
    std::vector<std::vector<std::string>> data = CSV.load();
    std::vector<TasksGroupMap> tgm;
    
    for(std::vector<std::string> x : data){
        TasksGroupMap tgm_instance = vector2data(x);
        tgm.push_back(tgm_instance);
    }
    
    std::sort(tgm.begin(), tgm.end(), [](TasksGroupMap a, TasksGroupMap b){
        return a.id_task_group_map < a.id_task_group_map;
    });

    return tgm;
}


bool TaskGroupMapModel::update(TasksGroupMap& obj){
    std::vector<TasksGroupMap> dataset = all();
    auto obj_it = std::find_if(dataset.begin(), dataset.end(), [obj](TasksGroupMap data){
        return data.id_task_group_map == obj.id_task_group_map;
    });
    if (obj_it != dataset.end()){
        dataset.erase(obj_it);
        dataset.push_back(obj);
    }
    return save_all(dataset);
}


int TaskGroupMapModel::getLastId(){
    return all().back().id_task_group_map;
}


bool TaskGroupMapModel::deleteData(TasksGroupMap& obj){
    auto dataset = all();
    auto obj_it = std::find_if(dataset.begin(), dataset.end(), [obj] (TasksGroupMap a){
        return obj.id_task_group_map == a.id_task_group_map;
    });

    if (obj_it == dataset.end()){
        std::cout << "Object not found" << std::endl;
        return false;
    }
    else
    {
        dataset.erase(obj_it);
        return save_all(dataset);
    }
    
}



// IMPLEMENTATIONS FOR TaskGroup STARTS HERE

std::vector<std::string> TaskGroupModel::data2vector(TaskGroup& obj){
    std::vector<std::string> data;

    data.push_back(std::to_string(obj.id_task_group));
    data.push_back(std::to_string(obj.user_id));
    data.push_back(obj.name);
    data.push_back(std::to_string(obj.created_by));
    // Find a way to serialize all users
    return data;
}


TaskGroup TaskGroupModel::vector2data(std::vector<std::string>& obj){
    TaskGroup tgm;
    tgm.id_task_group = stoi(obj[0]);
    tgm.user_id = stoi(obj[1]);
    tgm.name = obj[2];
    tgm.created_by = stoi(obj[3]);

    return tgm;
}


bool TaskGroupModel::save(TaskGroup& obj){
    std::vector<std::string> data = data2vector(obj);
    BaseModel CSV(filename);
    return CSV.save(data);
}


bool TaskGroupModel::save_all(std::vector<TaskGroup>& obj){
    bool flag = false;
    remove(filename.c_str());
    for (auto data : obj){
        flag = save(data);
    }
    return flag;
}


std::vector<TaskGroup> TaskGroupModel::all(){
    BaseModel CSV(filename);
    std::vector<std::vector<std::string>> data = CSV.load();
    std::vector<TaskGroup> tg;
    
    for(std::vector<std::string> x : data){
        TaskGroup tg_instance = vector2data(x);
        tg.push_back(tg_instance);
    }
    
    std::sort(tg.begin(), tg.end(), [](TaskGroup a, TaskGroup b){
        return a.id_task_group < a.id_task_group;
    });

    return tg;
}


bool TaskGroupModel::update(TaskGroup& obj){
    std::vector<TaskGroup> dataset = all();
    auto obj_it = std::find_if(dataset.begin(), dataset.end(), [obj](TaskGroup data){
        return data.id_task_group == obj.id_task_group;
    });
    if (obj_it != dataset.end()){
        dataset.erase(obj_it);
        dataset.push_back(obj);
    }
    return save_all(dataset);
}


int TaskGroupModel::getLastId(){
    return all().back().id_task_group;
}


bool TaskGroupModel::deleteData(TaskGroup& obj){
    auto dataset = all();
    auto obj_it = std::find_if(dataset.begin(), dataset.end(), [obj] (TaskGroup a){
        return obj.id_task_group == a.id_task_group;
    });

    if (obj_it == dataset.end()){
        std::cout << "Object not found" << std::endl;
        return false;
    }
    else
    {
        dataset.erase(obj_it);
        return save_all(dataset);
    }
    
}

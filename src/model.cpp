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


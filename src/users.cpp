#include "users.h"
#include "model.h"
// Definitions for User goes here

User::User(std::string aFirstName, std::string aLastName,
	std::string aUsername, std::string aEmail, std::string aPassword,
	std::string aPhone, std::string aAddress, time_t aCreated_at)
{
	firstName = aFirstName;
	lastName = aLastName;
	username = aUsername;
	email = aEmail;
	password = aPassword;
	phone = aPhone;
	address = aAddress;
}


User::~User()
{
	firstName.clear();
	lastName.clear();
	username.clear();
	email.clear();
	password.clear();
	phone.clear();
	address.clear();
	//std::cout << "Object is being deleted" << std::endl;
}


int User::registerUser()
{
	//Ask for the name
	string resName = validatename("");
	firstName = resName;

	//Ask for the name
	string resLastname = validteLastname("");
	lastName = resLastname;

	//Ask for the name
	string resUsername = validteUsername("");
	username = resUsername;

	//Ask for the name
	string resEmail = validateEmail("");
	email = resEmail;

	//Ask for the name
	string resPass = validatePassword("");
	password = resPass;

	//Ask for the name
	string resPhone = validtePhone("");
	phone = resPhone;

	//Ask for the name
	string resAddress = validteAddress("");
	address = resAddress;

	created_at = time(0);
	
	//validates that username does not exists
	unordered_map<string, string> mappinguser = getUserInfo(1);
	if (mappinguser["found"] == "1") {
		cout << " Username already registered, please try again!" << endl;
		return 0;
	}

	UserModel user;
	int lastId = user.getLastId();
	//generates user object with the data
	User u(firstName, lastName, username, email, password, phone, address, created_at);
	u.user_id = lastId + 1;
	//Save data in file
	user.save(u);

	return lastId;
}


void User::update()
{
	//lista data of the user
	unordered_map<string, string> mappinguser = getUserInfo(1);
	if (mappinguser["found"] == "1") {
		//display data
		cout << endl
			<< "  ******************************************" << endl
			<< "  *             INFORMATION                *" << endl
			<< "  ******************************************" << endl
			<< "  *----------------------------------------*" << endl
			<< "  * 1. First Name :  " << setw(10) << left << mappinguser["firstname"] << " " << endl
			<< "  *----------------------------------------*" << endl
			<< "  * 2. Last Name :  " << setw(10) << mappinguser["lastname"] << " " << endl
			<< "  *----------------------------------------*" << endl
			<< "  * 3. Username :  " << setw(10) << mappinguser["lastname"] << " " << endl
			<< "  *----------------------------------------*" << endl
			<< "  * 4. Email :  " << setw(10) << mappinguser["email"] << " " << endl
			<< "  *----------------------------------------*" << endl
			<< "  * 5. Phone :  " << setw(10) << mappinguser["phone"] << " " << endl
			<< "  *----------------------------------------*" << endl
			<< "  * 6. Address :  " << setw(10) << mappinguser["address"] << " " << endl
			<< "  *----------------------------------------*" << endl
			<< "  * 7. Password :  *************            " << endl
			<< "  ******************************************" << endl;
	}
	
	bool answer = processUpdating(mappinguser);
	if (answer == true) {
		cout << "Update done successfully\n";
	}
}


/**
* processUpdating
* Executes the validation of the field that the user has selected
* and validate it has the right format
*
* @param userInfo array with the current user data
* @return true(If the process is successful)/false(proccess fails)
*/
bool User::processUpdating(std::unordered_map<string, string>& mapping) {
	//FieldsValidator objValidator;
	//Registrator ObjRegistrator;
	int column;
	//Verify that the coice is correct
	do {
		cout << " Enter number of column to modify (1-7): ";
		cin >> column;
		cin.ignore(1);

		//Verifiy that column is between 1 and 8
		if ((!cin >> column) || column < 1 || 7 < column) {
			cin.clear();
			cout << "Wrong choice. Retry.\n";
		}

	} while ((!cin >> column) || column < 1 || 7 < column);
	
	//need to be  changed userInfo["date"]
	time_t t = time(NULL);

	//user Object
	User objUser(mapping["firstname"], mapping["lastname"], mapping["username"],
		mapping["email"], mapping["pass"], mapping["phone"], mapping["address"], t);
	objUser.user_id = stoi(mapping["usersId"]);
	
	//cout << "onject before update" << objUser.user_id << "-" << objUser.firstName << "-" << objUser.lastName << "-" << objUser.username;
	//cout << "-" << objUser.email << "-" << objUser.phone << "-" << objUser.address << "-" << objUser.password << endl;
	//As each type of data needs to be managed differently, there is a function for each one 
	if (column == 1) {
		objUser.firstName = validatename("new");
	}
	else if (column == 2) {
		objUser.lastName = validteLastname("new");
	}
	else if (column == 3) {
		objUser.username = validteUsername("new");
	}
	else if (column == 4) {
		objUser.email = validateEmail("new");
	}
	else if (column == 5) {
		objUser.phone = validtePhone("new");
	}
	else if (column == 6) {
		objUser.address = validteAddress("new");
	}
	else if (column == 7) {
		objUser.password = validatePassword("new");
	}
	else {
		cout << "Option no available.\n";
		return false;
	}

	cout << "object AFTER update" << objUser.user_id << "-" << objUser.firstName << "-" << objUser.lastName << "-" << objUser.username;
	cout << "-" << objUser.email << "-" << objUser.phone << "-" << objUser.address << "-" << objUser.password << endl;

	//CALL MAIKOL METHOD TO UPDATE SENDING THE USER OBJECT
	UserModel InstaceModel;
	//InstaceModel.update(objUser);
	//According the choice it needs to ask for a specific type of data
	return true;
}

//void User::getUserInfo()
unordered_map<string, string> User::getUserInfo(int typeofSearch)
{
	unordered_map<string, string> mapping;
	mapping["found"] = "0";
	mapping["usersId"] = "0";
	mapping["firstname"] = "0";
	mapping["lastname"] = "0";
	mapping["username"] = "0";
	mapping["pass"] = "0";
	mapping["email"] = "0";
	mapping["address"] = "";
	mapping["phone"] = "";
	mapping["date"] = "";
	UserModel user;
	
	//just search username
	if(typeofSearch == 1){
	//send new data
		for (auto x : user.all())
		{
			if (x.username == username) {
				std::cout << x.username << ", "  << x.user_id << ", " << x.lastName << ", " << x.firstName << std::endl;
				mapping["found"] = "1";
				mapping["usersId"] = to_string(x.user_id);
				mapping["firstname"] = x.firstName;
				mapping["lastname"] = x.lastName;
				mapping["username"] = x.username;
				mapping["pass"] = x.password;
				mapping["email"] = x.email;
				mapping["address"] = x.address;
				mapping["phone"] = x.phone;
				mapping["date"] = x.created_at;
				break;
			}

		}
	}else if(typeofSearch == 2) {
		//send new data
		for (auto x : user.all())
		{
			if (x.username == username && x.password == password) {
				//std::cout << x.username << ", " << x.lastName << ", " << x.firstName << std::endl;
				mapping["found"] = "1";
				mapping["usersId"] = x.user_id;
				mapping["firstname"] = x.firstName;
				mapping["lastname"] = x.lastName;
				mapping["username"] = x.username;
				mapping["pass"] = x.password;
				mapping["email"] = x.email;
				mapping["address"] = x.address;
				mapping["phone"] = x.phone;
				mapping["date"] = x.created_at;
				break;
			}

		}
	}
	return mapping;
}


void User::resetPassword()
{
	//call model
	//username email as key to identify the user
	//model::load(username)
	//::generateNewPassword(username)

}
void User::updatePassword()
{
	//call to ask for new password
	password = validatePassword("new");
	//username or email as key to identify the user
	//model::updatePassword(email, newpassword)

}
